#include "Plans/Serve/constraints/PickUp1520438299583Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1520438299583) ENABLED START*/
#include <ttb/wm/TaskManager.h>
#include <ttb/TTBWorldModel.h>

#include <ttb_msgs/ServeTask.h>

#include <alica/reasoner/DummyTerm.h>
#include <alica/reasoner/DummyVariable.h>

#include <engine/constraintmodul/ProblemDescriptor.h>
#include <engine/constraintmodul/SolverTerm.h>
#include <engine/constraintmodul/SolverVariable.h>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:PickUp

    /*		
     * Tasks: 
     * - EP:1520438315110 : Fetch (1520438413494)
     *
     * States:
     * - DriveToPickUpPos (1520438315109)
     * - Grap (1520438338624)
     * - PickedUp (1520438345249)
     * - Fail (1520516913557)
     *
     * Vars:				
     * - entity (1520438389375) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [entity]
     * Domain Variables:

     */
    void Constraint1520438401434::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1520438401434) ENABLED START*/
        auto wm = ttb::TTBWorldModel::get();
        auto currentTask = wm->taskManager.getNextTask();
        if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PICK_UP)
        {
            // current task is not for picking up an object, so don't specify any problem descriptor
            return;
        }

        auto constraint = std::make_shared<alica::reasoner::DummyTerm>();
        auto dummyEntityVar = std::dynamic_pointer_cast < alica::reasoner::DummyVariable > (c->getStaticVars()->at(0));
        if (dummyEntityVar)
        {
            constraint->setVariable(dummyEntityVar, currentTask->getInformation().entity);
        }
        else
        {
            std::cerr << "Constraint1520438401434: Variable type of Object Entity didn't fit!" << std::endl;
        }
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: DriveToPickUpPos

// State: DriveToPickUpPos

// State: Grap

// State: Grap

// State: PickedUp

// State: PickedUp

// State: Fail

// State: Fail

}
