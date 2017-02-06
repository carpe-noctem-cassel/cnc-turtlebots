#include "Plans/Serve/Serve1454331313621.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454331313621) ENABLED START*/ //Add additional using directives here
#include <TaskManager.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:Serve

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454331321920

     */
    shared_ptr<UtilityFunction> UtilityFunction1454331313621::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454331313621) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: WaitForTask in Plan: Serve

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : POI received 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1454331384091::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454331382859) ENABLED START*/
        if (this->wm->taskManager.isNextTask(::ttb::wm::TaskType::POI))
        {
            return true;
        }
        return false;

        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start box search 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1454331385501::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454331384188) ENABLED START*/
    	  if (this->wm->taskManager.isNextTask(::ttb::wm::TaskType::SEARCH))
    	        {
    	            return true;
    	        }
    	        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start pick up 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1486383787970::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1486383786264) ENABLED START*/
    	  if (this->wm->taskManager.isNextTask(::ttb::wm::TaskType::PICKUP))
    	        {
    	            return true;
    	        }
    	        return false;
        /*PROTECTED REGION END*/

    }

    //State: DriveTo in Plan: Serve

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : reached goal 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToWMsPOI, (PlanID): 1454330438527 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1454331503425::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454331501621) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: SearchFor in Plan: Serve

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : found all boxes 
     *
     * Plans in State: 				
     *   - Plan - (Name): SearchBoxes, (PlanID): 1481545038564 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1486383768270::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1486383766847) ENABLED START*/
    	return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: PickUp in Plan: Serve

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : picked up 
     *
     * Plans in State: 				
     *   - Plan - (Name): PickUpDefault, (PlanID): 1486381497239 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331321920)
     *
     * States:
     *   - WaitForTask (1454331321919)
     *   - DriveTo (1454331334336)
     *   - SearchFor (1454331358257)
     *   - PickUp (1486383776159)
     *
     * Vars:
     */
    bool TransitionCondition1486383790747::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1486383788195) ENABLED START*/
    	return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

}
