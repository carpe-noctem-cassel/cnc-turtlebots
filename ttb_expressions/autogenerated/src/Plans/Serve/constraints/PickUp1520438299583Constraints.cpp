#include "Plans/Serve/constraints/PickUp1520438299583Constraints.h"
/*PROTECTED REGION ID(ch1520438299583) ENABLED START*/
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/TaskManager.h>

#include <ttb_msgs/ServeTask.h>

#include <alica/reasoner/DummyTerm.h>
#include <alica/reasoner/DummyVariable.h>

#include <engine/constraintmodul/ProblemDescriptor.h>
#include <alica_solver_interface/SolverTerm.h>
#include <alica_solver_interface/SolverVariable.h>
/*PROTECTED REGION END*/

using std::cout;
using std::exception;
using std::make_shared;
using namespace alica;

namespace alicaAutogenerated
{
// Plan:PickUp
/*
 * Tasks:
 * - EP:1520438315110 : Fetch (1520438413494)
 *
 * States:
 * - DriveToPickUpPos (1520438315109)
 * - Grap (1520438338624)
 * - PickedUp (1520438345249)
 * - PickUpFail (1520516913557)
 * - DriveToObjectFail (1520589504282)
 *
 * Vars:
 * - entity (1520438389375)
 */
/*
 * RuntimeCondition - (Name): NewRuntimeCondition
 * (ConditionString):
 * Static Variables: entity
 * Domain Variables:
 *
 */
void Constraint1520438401434::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1520438401434) ENABLED START*/
    auto wm = ttb::TTBWorldModel::get();
    auto currentTask = wm->taskManager.getNextTask();
    if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PICK_UP) {
        // current task is not for picking up an object, so don't specify any problem descriptor
        auto constraint = new alica::reasoner::DummyTerm();
        for (auto var : c->getStaticVars()) {
            auto dummyVar = reinterpret_cast<alica::reasoner::DummyVariable*>(var);
            if (dummyVar) {
                constraint->setVariable(dummyVar, alica::reasoner::DummyVariable::NO_VALUE);
            }
        }
        c->setConstraint(constraint);
        return;
    }

    auto constraint = new alica::reasoner::DummyTerm();
    auto dummyEntityVar = reinterpret_cast<alica::reasoner::DummyVariable*>(c->getStaticVars().at(0));
    if (dummyEntityVar) {
        auto entity = currentTask->getInformation().entity;
        constraint->setVariable(dummyEntityVar, entity);
    } else {
        std::cerr << "Constraint1520438401434: Variable type of Object Entity didn't fit!" << std::endl;
    }
    c->setConstraint(constraint);
    /*PROTECTED REGION END*/
}

// State: DriveToPickUpPos
// State: Grap
// State: PickedUp
// State: PickUpFail
// State: DriveToObjectFail
} // namespace alicaAutogenerated