#include "Plans/Serve/ASPNavigateMaster1475692538365.h"
using namespace alica;
/*PROTECTED REGION ID(eph1475692538365) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ASPNavigateMaster

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- NavMasterVar (1475698052801)
     */
    bool RunTimeCondition1475692986360::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1475692986360) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1475692538367

     */
    shared_ptr<UtilityFunction> UtilityFunction1475692538365::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1475692538365) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

//State: Navigate in Plan: ASPNavigateMaster

}
