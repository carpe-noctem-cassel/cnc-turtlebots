#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>
#include "wumpus_simulator/SettingsDialog.h"

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0)
	{
		setObjectName("WumpusSimulator");
	}

	WumpusSimulator::~WumpusSimulator()
	{
	}

	void WumpusSimulator::initPlugin(qt_gui_cpp::PluginContext& context)
	{
		this->widget_ = new QWidget();
		this->widget_->setAttribute(Qt::WA_AlwaysShowToolTips, true);
		this->mainwindow.setupUi(this->widget_);

		if (context.serialNumber() > 1)
		{
			this->widget_->setWindowTitle(this->widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
		}
		context.addWidget(this->widget_);
		connect(this->mainwindow.settingsBtn, SIGNAL(released()), SLOT(on_settingsBtn_clicked()));
	}

	void WumpusSimulator::shutdownPlugin()
	{
	}

	void WumpusSimulator::saveSettings(qt_gui_cpp::Settings& plugin_settings,
										qt_gui_cpp::Settings& instance_settings) const
	{
	}

	void WumpusSimulator::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
											const qt_gui_cpp::Settings& instance_settings)
	{
	}

	void WumpusSimulator::on_settingsBtn_clicked()
	{
		auto settingsDialog = new SettingsDialog(this->widget_, this);
		settingsDialog->exec();
	}

}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)