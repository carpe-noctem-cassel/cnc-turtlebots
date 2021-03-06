/*
 * Box.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMARAMODEL_BOX_H_
#define SRC_LOGICALCAMARAMODEL_BOX_H_

#include <logicalCameraModel/LogicalObject.h>
#include <ros/ros.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm
	{
		class Box : public LogicalObject
		{
		public:
			Box(ttb_msgs::LogicalCameraPtr logicalCameraData);
			virtual ~Box();
		};
	}
}

#endif /* SRC_LOGICALCAMARAMODEL_BOX_H_ */
