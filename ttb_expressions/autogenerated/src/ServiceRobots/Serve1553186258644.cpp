#include "ServiceRobots/Serve1553186258644.h"
/*PROTECTED REGION ID(eph1553186258644) ENABLED START*/
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/TaskManager.h>
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:Serve
/* generated comment
    Task: DefaultTask  -> EntryPoint-ID: 1553186334263
*/
shared_ptr<UtilityFunction> UtilityFunction1553186258644::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1553186258644) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186819414, ConditionString: POI received, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Stop, (PlanID): 1553185137554
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553186819414::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186806326) ENABLED START*/
    if (this->wm->taskManager.isNextTask(ttb_msgs::ServeTask::DRIVE_TO)) {
        return true;
    }
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186845525, ConditionString: start pick up, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Stop, (PlanID): 1553185137554
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553186845525::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186839271) ENABLED START*/
    if (this->wm->taskManager.isNextTask(ttb_msgs::ServeTask::PICK_UP)) {
        return true;
    }
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186921238, ConditionString: start put down, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Stop, (PlanID): 1553185137554
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553186921238::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186914413) ENABLED START*/
    if (this->wm->taskManager.isNextTask(ttb_msgs::ServeTask::PUT_DOWN)) {
        return true;
    }
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186941342, ConditionString: start box search, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Stop, (PlanID): 1553185137554
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553186941342::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186936424) ENABLED START*/
    if (this->wm->taskManager.isNextTask(ttb_msgs::ServeTask::SEARCH)) {
        return true;
    }
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553246543385, ConditionString: reached goal | failed, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): DriveToPOI, (PlanID): 1553186299639
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553246543385::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553245775226) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success) || rp->isAnyChildStatus(PlanStatus::Failed);
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553246504180, ConditionString: picked up, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): PickUp, (PlanID): 1553186320902
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553246504180::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553246232965) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553246517033, ConditionString: finished putting object down, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): PutDown, (PlanID): 1553186313956
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553246517033::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553246237498) ENABLED START*/
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553246528041, ConditionString: found all boxes, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Search, (PlanID): 1553186306469
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553186334263)
 *
 * States:
 *
 *   - WaitForTask (1553186329060)
 *   - DriveToPOI (1553186370876)
 *   - PickUp (1553186372096)
 *   - PutDown (1553186373294)
 *   - SearchFor (1553186374398)
 *
 * Vars:
 */
bool PreCondition1553246528041::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553246242651) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated
