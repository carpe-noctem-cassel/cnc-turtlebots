#include "robot/SimulatedArm.h"

#include <LogicalCameraData.h>
#include <TTBWorldModel.h>

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

SimulatedArm::SimulatedArm()
{
    this->wm = ttb::TTBWorldModel::get();
    this->sc = supplementary::SystemConfig::getInstance();
    this->carriedObjectName = "";
    this->requestedObject = "";
    this->armRange = (*this->sc)["SimulatedArm"]->get<double>("SimulatedArm.Range", NULL);
    ros::NodeHandle n;
    this->doorCmdPub = n.advertise<ttb_msgs::DoorCmd>("/DoorCmd", 5, false);
    this->armCmdPub = n.advertise<ttb_msgs::GrabDropObject>("/ArmCmd", 5, false);
    this->robotName = this->sc->getHostname();
    std::string ownTopic = "/" + this->robotName + "/ArmCmd";
    this->armCmdSub = n.subscribe(ownTopic.c_str(), 10, &SimulatedArm::onOwnArmCmd, (SimulatedArm *)this);

    this->interactWithObject = ObjectInteraction::waiting;
    spinner = new ros::AsyncSpinner(4);
    spinner->start();
}

SimulatedArm::~SimulatedArm()
{
    spinner->stop();
    delete spinner;
}

void SimulatedArm::moveDoor(std::string doorName, bool open)
{
    ttb_msgs::DoorCmd msg;
    msg.name = doorName;
    if (open)
    {
        msg.state = ttb_msgs::DoorCmd::OPEN;
    }
    else
    {
        msg.state = ttb_msgs::DoorCmd::CLOSE;
    }
    this->doorCmdPub.publish(msg);
}

const std::string &SimulatedArm::getCarriedObjectName() const
{
    return carriedObjectName;
}

SimulatedArm::ObjectInteraction SimulatedArm::mayInteractWithObject()
{
    return this->interactWithObject;
}

bool SimulatedArm::grabObject(std::string objectName)
{
    if (objectName.empty() || !this->carriedObjectName.empty() || !this->requestedObject.empty())
    {
        return false;
    }
    auto objectToCarry = wm->logicalCameraData.getObject(objectName);
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.action = ttb_msgs::GrabDropObject::GRAB;
    this->armCmdPub.publish(msg);
    this->interactWithObject = ObjectInteraction::waiting;
    this->requestedObject = objectName;
    return true;
}

bool SimulatedArm::drobObject(std::string objectName)
{
    if (objectName.empty() || this->carriedObjectName.compare(objectName) != 0)
    {
        return false;
    }
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.action = ttb_msgs::GrabDropObject::DROP;
    this->armCmdPub.publish(msg);
    this->interactWithObject = ObjectInteraction::waiting;
    this->requestedObject = objectName;
    return true;
}

void SimulatedArm::onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg)
{
    if (msg->objectName.empty())
    {
        this->requestedObject = "";
        this->interactWithObject = ObjectInteraction::noInteractionAllowed;
        return;
    }
    if (msg->action == ttb_msgs::GrabDropObject::GRAB)
    {
        if (msg->senderName.compare(this->robotName) == 0 && msg->objectName.compare(this->requestedObject) == 0)
        {
            this->carriedObjectName = msg->objectName;
            this->requestedObject = "";
            this->interactWithObject = ObjectInteraction::interactionAllowed;
        }
    }
    else
    {
        if (msg->senderName.compare(this->robotName) == 0 && msg->objectName.compare(this->requestedObject) == 0)
        {
            this->carriedObjectName = "";
            this->requestedObject = "";
            this->interactWithObject = ObjectInteraction::interactionAllowed;
        }
    }
}

} /* namespace robot */
} /* namespace ttb */
