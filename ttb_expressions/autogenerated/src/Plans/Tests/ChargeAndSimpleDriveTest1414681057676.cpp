#include "Plans/Tests/ChargeAndSimpleDriveTest1414681057676.h"
using namespace alica;
/*PROTECTED REGION ID(eph1414681057676) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ChargeAndSimpleDriveTest

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1414681057678

     */
    shared_ptr<UtilityFunction> UtilityFunction1414681057676::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1414681057676) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: ChargeAndSimpleDriveTest

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : on robot start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447068027882::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447068026011) ENABLED START*/
//        if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr)
//                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::START)
//        {
//            return true;
//        }
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : akku too low (start temporary) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1414681278745 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447919930987::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447919928532) ENABLED START*/
        if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr)
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::START)
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: DriveForward in Plan: ChargeAndSimpleDriveTest

    /*
     *		
     * Transition:
     *   - Name: DoSomething2Stop, ConditionString: , Comment : on robot stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): SimpleDriveDefault, (PlanID): 1432735473356 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1414681505635::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1414681503803) ENABLED START*/
        if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr)
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::STOP)
        {
            return true;
        }

        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : on bumber activated 
     *
     * Plans in State: 				
     *   - Plan - (Name): SimpleDriveDefault, (PlanID): 1432735473356 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447068020434::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447068019298) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Rotating in Plan: ChargeAndSimpleDriveTest

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): RotateDefault, (PlanID): 1447068225787 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447068022583::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447068020601) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : on robot stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): RotateDefault, (PlanID): 1447068225787 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447068025867::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447068022712) ENABLED START*/
        if (wm->rawSensorData.getOwnRobotOnOff() != nullptr
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::STOP)
        {
            return true;
        }

        return false;
        /*PROTECTED REGION END*/

    }

    //State: SearchDockingStation in Plan: ChargeAndSimpleDriveTest

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any children success 
     *
     * Plans in State: 				
     *   - Plan - (Name): SearchDockingStationDefault, (PlanID): 1414681446065 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447958162066::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447958158825) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): SearchDockingStationDefault, (PlanID): 1414681446065 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447958174005::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447958171762) ENABLED START*/
        if (wm->rawSensorData.getOwnRobotOnOff() != nullptr
                && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::STOP)
        {
            return true;
        }

        return false;
        /*PROTECTED REGION END*/

    }

    //State: Charging in Plan: ChargeAndSimpleDriveTest

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : done loading (state 2 Docking charged) any children success 
     *
     * Plans in State: 				
     *   - Plan - (Name): ChargingDefault, (PlanID): 1447958132701 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1414681057678)
     *
     * States:
     *   - Stop (1414681057677)
     *   - DriveForward (1414681069778)
     *   - Rotating (1447067994402)
     *   - SearchDockingStation (1447919813367)
     *   - Charging (1447958080453)
     *
     * Vars:
     */
    bool TransitionCondition1447958165046::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447958162755) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success)
                || (wm->rawSensorData.getOwnRobotOnOff() != nullptr
                        && wm->rawSensorData.getOwnRobotOnOff()->cmd == robot_control::RobotCommand::STOP);
        /*PROTECTED REGION END*/

    }

}
