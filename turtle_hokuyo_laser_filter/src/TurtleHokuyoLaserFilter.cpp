/*
 * TurtleHokuyoLaserFilter.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Jonas Scherbaum
 */

#include "../include/TurtleHokuyoLaserFilter.h"
#include <thread>
#include <chrono>
#include <algorithm>

namespace turtle
{

  TurtleHokuyoLaserFilter::TurtleHokuyoLaserFilter()
  {

    this->laserScanSubscriber = this->nodeHandle.subscribe("/scan_hokuyo", 1, &TurtleHokuyoLaserFilter::laserScanCallback, this);
    this->laserScanFilteredPublisher = this->nodeHandle.advertise<sensor_msgs::LaserScan>("/scan_filtered", 10);
  }

  TurtleHokuyoLaserFilter::~TurtleHokuyoLaserFilter()
  {
    this->laserScanSubscriber.shutdown();
  }

  void TurtleHokuyoLaserFilter::laserScanCallback(sensor_msgs::LaserScanPtr msg)
  {
    // do not call in production mode
//    printLaserScan(msg);

    // start Interpolation here ...
    sensor_msgs::LaserScan::_ranges_type& ranges = msg->ranges;

    // brace 1
    float brace1_start = ranges.at(260);
    float brace1_end = ranges.at(300);
    float brace1_step_size = ranges.at(300) - brace1_start;
    brace1_step_size /= 40;

    // brace 2
    float brace2_start = ranges.at(330);
    float brace2_end = ranges.at(370);
    float brace2_step_size = ranges.at(370) - brace2_start;
    brace2_step_size /= 35;

    // brace 3
    float brace3_start = ranges.at(675);
    float brace3_end = ranges.at(715);
    float brace3_step_size = ranges.at(715) - brace3_start;
    brace3_step_size /= 35;

     // brace 4
    float brace4_start = ranges.at(745);
    float brace4_end = ranges.at(785);
    float brace4_step_size = ranges.at(785) - brace4_start;
    brace4_step_size /= 35;

    // now iterate over all range entries
    for (unsigned int i = 0; i<ranges.size(); i++) {

      if (i >= 785) {
        continue;
      }

      if (i > 745) {

        // replace with brace 4
        double curStep = 35-(625-i);
        double newVal = brace4_start;
        newVal += curStep*brace4_step_size;
        ranges.at(i) = std::min(brace4_start, brace4_end);
        continue;
      }

      if (i >= 715) {
        continue;
      }

      if (i > 675) {

        // replace with brace 3
        double curStep = 35-(555-i);
        double newVal = brace3_start;
        newVal += curStep*brace3_step_size;
        ranges.at(i) = std::min(brace3_start, brace3_end);
        continue;
      }

      if (i >= 370) {
        continue;
      }

      if (i > 330) {

        // replace with brace 2
        double curStep = 35-(210-i);
        double newVal = brace2_start;
        newVal += curStep*brace2_step_size;
        ranges.at(i) = std::min(brace2_start, brace2_end);
        continue;
      }

      if (i >= 300) {
        continue;
      }

      if (i > 260) {

        // replace with brace 1
        double curStep = 40-(140-i);
        double newVal = brace1_start;
        newVal += curStep*brace1_step_size;
        ranges.at(i) = std::min(brace1_start, brace1_end);;
        continue;
      }
    }

    std::reverse(ranges.begin(), ranges.end());

    // republish the filtered LaserScan
//    sensor_msgs::LaserScanConstPtr sendMsg = msg;
    this->laserScanFilteredPublisher.publish(msg);
  }

  void TurtleHokuyoLaserFilter::printLaserScan(sensor_msgs::LaserScanPtr msg)
  {
    float angle_inc = msg->angle_increment;
    float angle_max = msg->angle_max;
    float angle_min = msg->angle_min;
    sensor_msgs::LaserScan::_intensities_type intensities = msg->intensities;
    float range_max = msg->range_max;
    float range_min = msg->range_min;
    sensor_msgs::LaserScan::_ranges_type ranges = msg->ranges;
    float scan_time = msg->scan_time;
    float time_inc = msg->time_increment;

    // constructing human readable format
    std::ostringstream out;
    out << "Laser-Scan Message:" << std::endl;
    out << "Angle-Increment: " << angle_inc << std::endl;
    out << "Angle Maximum: " << angle_max << std::endl;
    out << "Angle Minimum: " << angle_min << std::endl;
    out << "Range Maximum: " << range_max << std::endl;
    out << "Range Minimum: " << range_min << std::endl;
    out << "Scan Time: " << scan_time << std::endl;
    out << "Time-Increment: " << time_inc << std::endl;

    out << "Intensities: " << std::endl;
    for (std::vector<float>::iterator it = intensities.begin(); it != intensities.end(); it++) {
      out << "it: " << *it;
    }
    out << std::endl;

    unsigned int count = 0;
    out << "Ranges: " << std::endl;
    for (std::vector<float>::iterator it = ranges.begin(); it != ranges.end(); it++) {
      out << "range[" << count << "]: "<< *it;
      count++;
    }
    out << std::endl;

    ROS_INFO("%s\n", out.str().c_str());
  }

} /* namespace turtle */

/**
 * The main EntryPoint of the turtle_base Node
 */
int main(int argc, char** argv)
{
    // start the Node with the name AlicaEngine
    ROS_DEBUG("Initializing Ros");
    ros::init(argc, argv, "TurtleHokuyoLaserFilter");

    ROS_DEBUG("Starting Base");

    // Read the argv Arguments for the Settings

    // node intialization comes here
    turtle::TurtleHokuyoLaserFilter* node = new turtle::TurtleHokuyoLaserFilter();

    ros::Rate publishRate(10);
    // While ROS is active, do the Node Stuff
    while (ros::ok())
    {
            // At the moment we are only waiting
            ros::spinOnce();
            publishRate.sleep();
    }

    return 0;
}
