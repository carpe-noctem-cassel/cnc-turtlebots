#include "Plans/Serve/ASPNavwoExternalsInner1477229638868.h"
/*PROTECTED REGION ID(eph1477229638868) ENABLED START*/
// Add additional using directives here
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:ASPNavwoExternalsInner
// Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :

/*
 * Available Vars:
 *	- PlanVar2 (1477229909334)
 */
bool RunTimeCondition1477229712321::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1477229712321) ENABLED START*/
    return true;
    /*PROTECTED REGION END*/
}
/* generated comment
    Task: DefaultTask  -> EntryPoint-ID: 1477229659175
*/
shared_ptr<UtilityFunction> UtilityFunction1477229638868::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1477229638868) ENABLED START*/
    shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: MISSING_NAME, ConditionString: , Comment : success
 *
 * Plans in State:
 *   - Plan - (Name): ASPNavwoExt, (PlanID): 1477229760910
 *
 * Tasks:
 *   - DefaultTask (1414681164704) (Entrypoint: 1477229659175)
 *
 * States:
 *   - Nav2 (1477229659174)
 *   - NewSuccessState (1479298294756)
 *
 * Vars:
 */
bool PreCondition1479298302100::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1479298299806) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated
