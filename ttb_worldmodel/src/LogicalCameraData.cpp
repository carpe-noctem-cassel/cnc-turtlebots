/*
 * LogicalCameraData.cpp
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */
#include <LogicalCameraData.h>

#include <logicalCameraModel/Box.h>
#include <logicalCameraModel/Fire.h>
#include <logicalCameraModel/Victim.h>
#include <logicalCameraModel/Landmark.h>

#include <algorithm>
#include <iostream>
#include <memory>

namespace ttb
{
	namespace wm
	{
		LogicalCameraData::LogicalCameraData()
		{
		}

		LogicalCameraData::~LogicalCameraData()
		{
		}

		void LogicalCameraData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData)
		{
//			cout << "logicalCameraData->type = " << logicalCameraData->type << endl;
			string type = logicalCameraData->type;

			auto logicalObjectsList = this->dict.find(type);
			if (logicalObjectsList != this->dict.end())
			{
				// found type
				auto logicalObjectEntry = std::find_if(logicalObjectsList->second.begin(),
														logicalObjectsList->second.end(),
														[logicalCameraData] (const shared_ptr<LogicalObject>& obj)
														{
															return obj->name.compare(logicalCameraData->modelName) == 0;
														});

				if (logicalObjectEntry != logicalObjectsList->second.end())
				{
					// found object
					logicalObjectEntry.operator ->()->operator ->()->processData(logicalCameraData);
				}
				else
				{
					// does not exist, yet
					logicalObjectsList->second.push_back(this->createLogicalObject(logicalCameraData));
				}
			}
			else
			{
				// type not present, yet
				this->dict[type] = list<shared_ptr<LogicalObject>>();
				this->dict[type].push_back(this->createLogicalObject(logicalCameraData));
			}
		}

		std::list<shared_ptr<LogicalObject>> LogicalCameraData::getLogicalObjects(string type)
		{
			auto list = this->dict.find(type);
			if (list == this->dict.end())
			{
				return std::list<shared_ptr<LogicalObject>>();
			}
			else
			{
				return list->second;
			}
		}

		std::shared_ptr<LogicalObject> LogicalCameraData::createLogicalObject(
				ttb_msgs::LogicalCameraPtr logicalCameraData)
		{
			if (logicalCameraData->type.compare("victim") == 0)
			{
				return std::make_shared<Victim>(logicalCameraData);
			}
			else if (logicalCameraData->type.compare("fire") == 0)
			{
				return std::make_shared<Fire>(logicalCameraData);
			}
			else if (logicalCameraData->type.compare("box") == 0)
			{
				return std::make_shared<Box>(logicalCameraData);
			}
			else if (logicalCameraData->type.compare("landmark") == 0)
			{
				return std::make_shared<Landmark>(logicalCameraData);
			}
			else
			{
				std::cerr << "LogicalCameraData::createLogicalObject: Unknown Logical Camera Object Type " << logicalCameraData->type << "!" << std::endl;
				return nullptr;
			}
		}
	}
}

