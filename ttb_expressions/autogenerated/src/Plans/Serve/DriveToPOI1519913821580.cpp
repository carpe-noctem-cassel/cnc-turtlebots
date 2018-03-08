#include "Plans/Serve/DriveToPOI1519913821580.h"
using namespace alica;
/*PROTECTED REGION ID(eph1519913821580) ENABLED START*/ // Add additional using directives here
#include <TurtleBot.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DriveToPOI

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- door (1519913984042)
     *	- poi (1519913989387)
     */
    bool RunTimeCondition1519914269940::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519914269940) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1519913874346

     */
    shared_ptr<UtilityFunction> UtilityFunction1519913821580::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1519913821580) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DriveToPOI in Plan: DriveToPOI

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : From POI to door: current POI should be reached. 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPOIDefault, (PlanID): 1519913781149 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1519913874346)
     *
     * States:
     *   - DriveToPOI (1519913874345)
     *   - OpenDoor (1519913892405)
     *   - AtGoalPOI (1519914080351)
     *   - WasBlocked (1519914308674)
     *
     * Vars:
     */
    bool TransitionCondition1519913901102::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519913899492) ENABLED START*/
        auto currentTask = this->wm->taskManager.getNextTask();
        if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::DRIVE_TO)
        {
            // current task is not for driving to an POI, so don't specify any problem descriptor
            return false;
        }

        auto currentGoalPOI = wm->topologicalModel.getPOI(stoi(currentTask->getInformation().entity));
        if (!currentGoalPOI)
        {
            // unable to get the goalPOI
            return false;
        }

        return rp->anyChildrenStatus(PlanStatus::Success) && !wm->robot.inSameRoom(currentGoalPOI);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Goal POI reached 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPOIDefault, (PlanID): 1519913781149 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1519913874346)
     *
     * States:
     *   - DriveToPOI (1519913874345)
     *   - OpenDoor (1519913892405)
     *   - AtGoalPOI (1519914080351)
     *   - WasBlocked (1519914308674)
     *
     * Vars:
     */
    bool TransitionCondition1519914093807::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519914091859) ENABLED START*/
        auto currentTask = this->wm->taskManager.getNextTask();
        if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::DRIVE_TO)
        {
            // current task is not for driving to an POI, so don't specify any problem descriptor
            return false;
        }

        auto currentGoalPOI = wm->topologicalModel.getPOI(stoi(currentTask->getInformation().entity));
        if (!currentGoalPOI)
        {
            // unable to get the goalPOI
            return false;
        }

        if (!this->wm->robot.isCloseTo(currentGoalPOI) || !this->wm->robot.inSameRoom(currentGoalPOI))
        {
            return false;
        }
        else
        {
            std::cout << "DriveToPOI-Plan: Arrived at goalPOI " << currentGoalPOI->id << std::endl;
            this->wm->taskManager.popNextTask();
            return true;
        }
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Unable to get to the goal POI 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPOIDefault, (PlanID): 1519913781149 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1519913874346)
     *
     * States:
     *   - DriveToPOI (1519913874345)
     *   - OpenDoor (1519913892405)
     *   - AtGoalPOI (1519914080351)
     *   - WasBlocked (1519914308674)
     *
     * Vars:
     */
    bool TransitionCondition1519914333760::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519914331850) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    //State: OpenDoor in Plan: DriveToPOI

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : From Door to POI state: Door should be open now. 
     *
     * Plans in State: 				
     *   - Plan - (Name): OpenDoorDefault, (PlanID): 1519913968184 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1519913874346)
     *
     * States:
     *   - DriveToPOI (1519913874345)
     *   - OpenDoor (1519913892405)
     *   - AtGoalPOI (1519914080351)
     *   - WasBlocked (1519914308674)
     *
     * Vars:
     */
    bool TransitionCondition1519913902356::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519913901227) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Unable to open some door! 
     *
     * Plans in State: 				
     *   - Plan - (Name): OpenDoorDefault, (PlanID): 1519913968184 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1519913874346)
     *
     * States:
     *   - DriveToPOI (1519913874345)
     *   - OpenDoor (1519913892405)
     *   - AtGoalPOI (1519914080351)
     *   - WasBlocked (1519914308674)
     *
     * Vars:
     */
    bool TransitionCondition1519914331734::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1519914329278) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

//State: AtGoalPOI in Plan: DriveToPOI

//State: WasBlocked in Plan: DriveToPOI

}
