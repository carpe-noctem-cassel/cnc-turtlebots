#pragma once

#include <rqt_gui_cpp/plugin.h>

#include <supplementary/AgentID.h>
#include "ros/ros.h"
#include <ttb_control/Robot.h>
#include <ros/macros.h>

//#include <msl_actuator_msgs/KickerStatInfo.h>
//#include <msl_sensor_msgs/SharedWorldInfo.h>

#include <QDialog>
#include <QWidget>
#include <QtGui>
#include <ui_TTBControl.h>

#include <chrono>
#include <mutex>
#include <queue>
#include <utility>

namespace supplementary
{
class SystemConfig;
class RobotExecutableRegistry;
}

namespace ttb_control
{

class TTBControl : public rqt_gui_cpp::Plugin
{

    Q_OBJECT

  public:
    TTBControl();
    virtual void initPlugin(qt_gui_cpp::PluginContext &context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings &plugin_settings, qt_gui_cpp::Settings &instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings &plugin_settings,
                                 const qt_gui_cpp::Settings &instance_settings);

    void addRobot();
    void removeRobot();

    static std::chrono::duration<double> msgTimeOut;

    Ui::RobotControlWidget robotControlWidget_;
    QWidget *widget_;

    supplementary::RobotExecutableRegistry *pmRegistry;
    ros::NodeHandle *rosNode;

  private:

    supplementary::SystemConfig *sc;

    std::map<const supplementary::AgentID*, Robot *> controlledRobotsMap;
    void processMessages();
    void checkAndInit(const supplementary::AgentID* robotId);

    QTimer *guiUpdateTimer;

  public Q_SLOTS:
    void run();
    void updateGUI();
    void showContextMenu(const QPoint &pos);
};
}
