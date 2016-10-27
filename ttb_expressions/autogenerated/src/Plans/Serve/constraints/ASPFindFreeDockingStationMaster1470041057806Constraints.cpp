#include "Plans/Serve/constraints/ASPFindFreeDockingStationMaster1470041057806Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1470041057806) ENABLED START*/
#include <alica_asp_solver/Term.h>
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include <memory>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:ASPFindFreeDockingStationMaster

    /*		
     * Tasks: 
     * - EP:1470041057809 : DefaultTask (1414681164704)
     *
     * States:
     * - SearchForFreeDockingStation (1470041057808)
     * - Charge (1470041204046)
     * - NewSuccessState (1470042244415)
     *
     * Vars:				
     * - DockingStationVar (1470043579268) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [DockingStationVar]
     * Domain Variables:

     */
    void Constraint1470042926317::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1470042926317) ENABLED START*/
        auto constraint = make_shared<alica::reasoner::Term>();
        constraint->setRule("freeDockingStation(X) :- poi(X), dockingStation(X), not occupied(X,Y) : agent(Y).");
        constraint->addFact("dockingStation(studentLab1).");
        constraint->addFact("dockingStation(kicker).");
        constraint->addFact("agent(donatello).");
        constraint->addFact("occupied(kicker, donatello).");
        constraint->setProgrammSection("distributedSystemsRooms");
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: SearchForFreeDockingStation

// State: SearchForFreeDockingStation

// State: Charge

// State: Charge

// State: NewSuccessState

// State: NewSuccessState

}
