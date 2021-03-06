#include "Plans/Serve/Charge1454331030770.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454331030770) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:Charge

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454331045285

     */
    shared_ptr<UtilityFunction> UtilityFunction1454331030770::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454331030770) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: SearchDock in Plan: Charge

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : docked | fully charged (child success) 
     *
     * Plans in State: 				
     *   - Plan - (Name): SearchDockingStationDefault, (PlanID): 1414681446065 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331045285)
     *
     * States:
     *   - SearchDock (1454331097632)
     *   - ChargeAccu (1454331108755)
     *   - FullyCharged (1454331131268)
     *
     * Vars:
     */
    bool TransitionCondition1454331127179::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454331126208) ENABLED START*/
        if (this->fullyCharged() || this->isCharging())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: ChargeAccu in Plan: Charge

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : accu full 
     *
     * Plans in State: 				
     *   - Plan - (Name): ChargingDefault, (PlanID): 1447958132701 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454331045285)
     *
     * States:
     *   - SearchDock (1454331097632)
     *   - ChargeAccu (1454331108755)
     *   - FullyCharged (1454331131268)
     *
     * Vars:
     */
    bool TransitionCondition1454331145639::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454331143741) ENABLED START*/
        if (this->fullyCharged())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

//State: FullyCharged in Plan: Charge

}
