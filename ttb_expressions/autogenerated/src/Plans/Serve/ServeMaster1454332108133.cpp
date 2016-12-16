#include "Plans/Serve/ServeMaster1454332108133.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454332108133) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ServeMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454332108135

     */
    shared_ptr<UtilityFunction> UtilityFunction1454332108133::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454332108133) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: ServeMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454332108135)
     *
     * States:
     *   - Stop (1454332108134)
     *   - Serve (1454332119685)
     *   - Charge (1454332121310)
     *
     * Vars:
     */
    bool TransitionCondition1454332147978::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454332146639) ENABLED START*/
        if (this->checkLastCommand(robot_control::RobotCommand::START))
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Serve in Plan: ServeMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : low accu (not implemented, yet) 
     *
     * Plans in State: 				
     *   - Plan - (Name): CollectBoxes, (PlanID): 1481544845570 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454332108135)
     *
     * States:
     *   - Stop (1454332108134)
     *   - Serve (1454332119685)
     *   - Charge (1454332121310)
     *
     * Vars:
     */
    bool TransitionCondition1454332144469::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454332142505) ENABLED START*/
        if (this->wm->rawSensorData.getOwnMobileBaseSensorState()->battery < 150)
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): CollectBoxes, (PlanID): 1481544845570 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454332108135)
     *
     * States:
     *   - Stop (1454332108134)
     *   - Serve (1454332119685)
     *   - Charge (1454332121310)
     *
     * Vars:
     */
    bool TransitionCondition1454332146510::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454332145537) ENABLED START*/
        if (this->checkLastCommand(robot_control::RobotCommand::STOP))
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Charge in Plan: ServeMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): Charge, (PlanID): 1454331030770 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454332108135)
     *
     * States:
     *   - Stop (1454332108134)
     *   - Serve (1454332119685)
     *   - Charge (1454332121310)
     *
     * Vars:
     */
    bool TransitionCondition1454332142376::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454332141413) ENABLED START*/
        if (this->checkLastCommand(robot_control::RobotCommand::STOP))
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : fully charged (child success) 
     *
     * Plans in State: 				
     *   - Plan - (Name): Charge, (PlanID): 1454331030770 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454332108135)
     *
     * States:
     *   - Stop (1454332108134)
     *   - Serve (1454332119685)
     *   - Charge (1454332121310)
     *
     * Vars:
     */
    bool TransitionCondition1454332145416::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454332144573) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

}
