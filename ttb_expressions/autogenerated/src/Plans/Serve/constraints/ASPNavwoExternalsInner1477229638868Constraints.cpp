#include "Plans/Serve/constraints/ASPNavwoExternalsInner1477229638868Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1477229638868) ENABLED START*/
//Add additional using directives here
#include <alica_asp_solver/Term.h>
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include <memory>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:ASPNavwoExternalsInner

    /*		
     * Tasks: 
     * - EP:1477229659175 : DefaultTask (1414681164704)
     *
     * States:
     * - Nav2 (1477229659174)
     *
     * Vars:				
     * - PlanVar2 (1477229909334) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [PlanVar2]
     * Domain Variables:

     */
    void Constraint1477229712321::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1477229712321) ENABLED START*/
        auto constraint = make_shared<alica::reasoner::Term>();
        constraint->setRule(
                "goalReachable(X, 2) :- reachable(X, Y, 2), goal(X, 2), start(Y, 2), room(X, 2), room(Y, 2).");
        constraint->addFact("goal(r1405B, 2).");
        constraint->addFact("start(r1411, 2).");
        constraint->setBackgroundFileName("distributedSystemsRooms2");
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: Nav2

// State: Nav2

}
