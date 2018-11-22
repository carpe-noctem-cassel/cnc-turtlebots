#include "ttb/wm/Communication.h"

#include "ttb/TTBWorldModel.h"
#include "ttb/WrappedMessageHandler.h"

#include <supplementary/AgentID.h>
#include <supplementary/BroadcastID.h>

using std::string;

namespace ttb
{
namespace wm
{

Communication::Communication(ttb::TTBWorldModel* wm)
        : wm(wm)
{
    this->timeLastSimMsgReceived = alica::AlicaTime::zero();
    auto sc = wm->getSystemConfig();
    // SET ROS STUFF
    string topic;
    if (wm->isUsingSimulator()) {
#ifdef COMM_DEBUG
        std::cout << "Communication: In SIMULATION mode." << std::endl;
#endif
        // for simulated robot only
        topic = (*sc)["TTBWorldModel"]->get<string>("Data.LogicalCamera.Topic", NULL);
        logicalCameraSensorSub = n.subscribe(topic, 10, &Communication::onLogicalCamera, (Communication*) this);

        topic = (*sc)["TTBWorldModel"]->get<string>("Data.GazeboModelStates.Topic", NULL);
        gazeboModelStatesSub = n.subscribe(topic, 10, &Communication::onGazeboModelStates, (Communication*) this);
    } else {
#ifdef COMM_DEBUG
        std::cout << "Communication: In REAL ROBOT mode." << std::endl;
#endif
        // for real robot only

        topic = (*sc)["TTBWorldModel"]->get<string>("Data.DockInfrRed.Topic", NULL);
        dockInfrRedSub = n.subscribe(topic, 10, &Communication::onDockInfrRed, (Communication*) this);

        topic = (*sc)["TTBWorldModel"]->get<string>("Data.MobileBaseSensorState.Topic", NULL);
        mobileBaseSensorStateSub = n.subscribe(topic, 10, &Communication::onMobileBaseSensorState, (Communication*) this);

        topic = (*sc)["TTBWorldModel"]->get<string>("Data.AlvarMarker.Topic", NULL);
        alvarSub = n.subscribe(topic, 10, &Communication::onAlvarMarkers, (Communication*) this);
    }

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.AMCLPose.Topic", NULL);
    amclPoseSub = n.subscribe(topic, 10, &Communication::onAMCLPose, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.RawCameraImage.Topic", NULL);
    cameraImageRawSub = n.subscribe(topic, 10, &Communication::onRawCameraImage, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.Odometry.Topic", NULL);
    odometrySub = n.subscribe(topic, 10, &Communication::onOdometry, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.LaserScan.Topic", NULL);
    laserScanSub = n.subscribe(topic, 10, &Communication::onLaserScan, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.DepthCameraCloud.Topic", NULL);
    cameraPclSub = n.subscribe(topic, 10, &Communication::onDepthCameraCloud, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.CliffEvent.Topic", NULL);
    cliffEventsSub = n.subscribe(topic, 10, &Communication::onCliffEvent, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.BumperSensor.Topic", NULL);
    bumperSensorSub = n.subscribe(topic, 10, &Communication::onBumperCloud, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.BumperEvent.Topic", NULL);
    bumperEventSub = n.subscribe(topic, 10, &Communication::onBumperEvent, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.IMUData.Topic", NULL);
    imuDataSub = n.subscribe(topic, 10, &Communication::onImu, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.RobotCommand.Topic", NULL);
    robotCommandSub = n.subscribe(topic, 10, &Communication::onRobotCommand, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.ServeTask.Topic", NULL);
    serveTaskSub = n.subscribe(topic, 10, &Communication::onServeTask, (Communication*) this);

    wrappedMessageHandler = nullptr;
    //    wrappedMessageHandler = new WrappedMessageHandler();
    //    wrappedMessageHandler->init(this->wm->getOwnId(), this->wm->getEngine());

    spinner = new ros::AsyncSpinner(4);
    spinner->start();
}

Communication::~Communication()
{
    spinner->stop();
    delete spinner;
    delete wrappedMessageHandler;
}

alica::AlicaTime Communication::getTimeLastSimMsgReceived()
{
    return this->timeLastSimMsgReceived;
}

void Communication::onAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvar)
{
    this->wm->rawSensorData.processAlvarMarkers(alvar);
}

void Communication::onOdometry(nav_msgs::OdometryPtr odometry)
{
    this->wm->rawSensorData.processOdometry(odometry);
}

void Communication::onLaserScan(sensor_msgs::LaserScanPtr laserScan)
{
    this->wm->rawSensorData.processLaserScan(laserScan);
}

void Communication::onBumperCloud(sensor_msgs::PointCloud2Ptr bumperCloud)
{
    this->wm->rawSensorData.processBumperCloud(bumperCloud);
}

void Communication::onBumperEvent(kobuki_msgs::BumperEvent bumperEvent)
{
    this->wm->rawSensorData.processBumperEvent(bumperEvent);
}

void Communication::onImu(sensor_msgs::Imu imu)
{
    this->wm->rawSensorData.processImu(imu);
}

void Communication::onDepthCameraCloud(sensor_msgs::PointCloud2Ptr depthCameraCloud)
{
    this->wm->rawSensorData.processDepthCameraCloud(depthCameraCloud);
}

void Communication::onCliffEvent(kobuki_msgs::CliffEvent cliffEvent)
{
    this->wm->rawSensorData.processCliffEvent(cliffEvent);
}

void Communication::onRawCameraImage(sensor_msgs::ImagePtr rawCameraImage)
{
    this->wm->rawSensorData.processRawCameraImage(rawCameraImage);
}

void Communication::onRobotCommand(robot_control::RobotCommand robotCommand)
{
    this->wm->rawSensorData.processRobotCommand(robotCommand);
}

void Communication::onMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorState)
{
    this->wm->rawSensorData.processMobileBaseSensorState(mobileBaseSensorState);
}

void Communication::onDockInfrRed(kobuki_msgs::DockInfraRed dockInfrRed)
{
    this->wm->rawSensorData.processDockInfrRed(dockInfrRed);
}

void Communication::onServeTask(ttb_msgs::ServeTask serveTask)
{
    auto ownID = this->wm->getOwnId();
    auto senderId = this->wm->getEngine()->getIdFromBytes(serveTask.sender.id);
    auto receiverId = this->wm->getEngine()->getIdFromBytes(serveTask.receiver.id);
    if (*senderId != *ownID && (*receiverId == *ownID || serveTask.receiver.type == supplementary::BroadcastID::BC_TYPE)) {
        this->wm->rawSensorData.processServeTask(serveTask);
    }
}

void Communication::onAMCLPose(geometry_msgs::PoseWithCovarianceStamped msg)
{
    if (this->wm->isUsingSimulator()) { // this data is send by the "fake_localization" node in case of a simulator scenario
        this->timeLastSimMsgReceived = this->wm->getTime();
    }

    this->wm->rawSensorData.processAMCLPose(msg);
}

void Communication::onLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera)
{
    this->wm->rawSensorData.processLogicalCamera(logicalCamera);
    this->wm->logicalCameraData.processLogicalCamera(logicalCamera);
}

void Communication::onGazeboModelStates(gazebo_msgs::ModelStatesPtr modelStates)
{
    this->wm->rawSensorData.processGazeboModelState(modelStates);
}

} /* namespace wm */
} /* namespace ttb */