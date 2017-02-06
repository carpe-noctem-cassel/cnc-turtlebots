/*
 * ServeTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_SERVETASK_H_
#define SRC_TASKS_SERVETASK_H_
#include <TaskManager.h>

namespace ttb
{
namespace wm
{

class ServeTask
{
  public:
    ServeTask();
    virtual ~ServeTask();
    std::string name;
    TaskType type;
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_SERVETASK_H_ */