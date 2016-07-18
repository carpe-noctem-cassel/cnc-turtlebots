#include "Plans/Serve/constraints/CarryBook1468494583802Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1468494583802) ENABLED START*/
#include <alica_asp_solver/Term.h>
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include <memory>
//Add additional using directives here
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:CarryBook

    /*		
     * Tasks: 
     * - EP:1468494595479 : DefaultTask (1414681164704)
     *
     * States:
     * - CarryBook (1468494595478)
     *
     * Vars:				
     * - BookPlanVar (1468494716925) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [BookPlanVar]
     * Domain Variables:

     */
    void Constraint1468495216221::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1468495216221) ENABLED START*/
    	auto constraint = make_shared<alica::reasoner::Term>();
    	constraint->setRule("freeFairyTailBook(X) :- book(X), genre(fairyTail), bookGenre(X, fairyTail), agent(Y), not on(X,Y).");
    	constraint->setBackgroundFileName("bookExample");
    	c->setConstraint(dynamic_pointer_cast <alica::SolverTerm> (constraint));
        /*PROTECTED REGION END*/
    }

// State: CarryBook

// State: CarryBook

}
