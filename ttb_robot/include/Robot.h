#pragma once

#include "robot/SimulatedArm.h"
#include "robot/Movement.h"

namespace ttb
{

class Robot
{
  public:
	virtual ~Robot();
	static Robot *get(); /**< Singleton Getter */

	robot::SimulatedArm* simulatedArm;
	robot::Movement* movement;

  private:
	Robot();
};

} /* namespace ttb */
