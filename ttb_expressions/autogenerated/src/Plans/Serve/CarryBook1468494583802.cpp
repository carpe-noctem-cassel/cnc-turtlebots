#include "Plans/Serve/CarryBook1468494583802.h"
using namespace alica;
/*PROTECTED REGION ID(eph1468494583802) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:CarryBook

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- BookPlanVar (1468494716925)
     */
    bool RunTimeCondition1468495216221::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1468495216221) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    //Check of PreCondition - (Name): NewPreCondition, (ConditionString): agent(A), in(A,p1468494583802, tsk1468494595479, S),  carries(A, harryPotter1). , (Comment) :  

    /*
     * Available Vars:
     */
    bool PreCondition1468919500674::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1468919500674) ENABLED START*/
        //--> "PreCondition:1468919500674  not implemented";
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1468494595479

     */
    shared_ptr<UtilityFunction> UtilityFunction1468494583802::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1468494583802) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: CarryBook in Plan: CarryBook

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): CarryDefault, (PlanID): 1468494631985 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1468494595479)
     *
     * States:
     *   - CarryBook (1468494595478)
     *   - NewSuccessState (1468919156738)
     *
     * Vars:
     */
    bool TransitionCondition1468919192856::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1468919190912) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: CarryBook

}
