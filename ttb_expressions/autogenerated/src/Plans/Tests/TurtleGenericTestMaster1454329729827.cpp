#include "Plans/Tests/TurtleGenericTestMaster1454329729827.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454329729827) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:TurtleGenericTestMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454329729829

     */
    shared_ptr<UtilityFunction> UtilityFunction1454329729827::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454329729827) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: TurtleGenericTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454329729829)
     *
     * States:
     *   - Stop (1454329729828)
     *   - Test (1454329743284)
     *
     * Vars:
     */
    bool TransitionCondition1454329746996::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454329745494) ENABLED START*/
        if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr)
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::START)
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Test in Plan: TurtleGenericTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): TestPOI, (PlanID): 1454329810785 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454329729829)
     *
     * States:
     *   - Stop (1454329729828)
     *   - Test (1454329743284)
     *
     * Vars:
     */
    bool TransitionCondition1454329748126::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454329747260) ENABLED START*/
        if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr)
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::STOP)
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

}
