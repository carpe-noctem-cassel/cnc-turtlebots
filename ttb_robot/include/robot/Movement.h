#pragma once

#include <supplementary/Worker.h>

#include <robot/TTBEnums.h>
#include <cnc_geometry/CNPositionAllo.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/action_client.h>

#include <ros/ros.h>

#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace supplementary
{
class SystemConfig;
}

namespace ttb
{
class TTBWorldModel;
class Robot;
namespace wm
{
class Area;
class Room;
class Door;
class POI;
}
namespace robot
{
namespace pathPlanning
{
class TopologicalPathPlanner;
}

class Movement : public supplementary::Worker
{
  public:
    Movement(ttb::TTBWorldModel *wm, ttb::Robot *robot);
    virtual ~Movement();

    // direct moves
    void send(geometry_msgs::Twist &twist);

    // move base
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> send(move_base_msgs::MoveBaseGoal &mbg);
    void cancelAllGoals();
    void cancelGoalsAtAndBeforeTime(const ros::Time &time);

    // complex planning
    ttb::robot::MovementReturnState getState(std::shared_ptr<ttb::wm::POI> goal);
    void setGoalPOI(std::shared_ptr<ttb::wm::POI> goal);
    bool determineGoalRoom(std::shared_ptr<::ttb::wm::Room> start, std::shared_ptr<::ttb::wm::Area> goal,
                           std::shared_ptr<ttb::wm::Room>& goalRoom, std::shared_ptr<ttb::wm::Door>& doorToNextArea);
    bool closeToPOI(geometry::CNPositionAllo ownPos, std::shared_ptr<ttb::wm::POI> currentPOI);
    virtual void run();

  private:
    supplementary::SystemConfig *sc;
    ttb::TTBWorldModel *wm;
    ttb::Robot *robot;
    ros::NodeHandle n;

    // direct moves
    std::string directVelocityCmd;
    ros::Publisher directVelocityCmdPub;

    // move base
    std::string moveBaseActionClientNamespace;
    actionlib::ActionClient<move_base_msgs::MoveBaseAction> *ac;
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;

    // complex planning
    void reset();
    ttb::robot::pathPlanning::TopologicalPathPlanner *topoPlanner;
    std::vector<std::shared_ptr<ttb::wm::Area>> currentPath;
    std::vector<std::shared_ptr<ttb::wm::Door>> currentPathInArea;
    std::shared_ptr<ttb::wm::POI> goalPOI;
    bool goalPOIDirty;
    std::shared_ptr<ttb::wm::Door> doorToOpen;
    std::mutex goalMutex;
    bool goalReached, goalFailed;
    double sqrCatchRadius;
    uint32_t sequenceCounter;
};

} /* namespace robot */
} /* namespace ttb */
