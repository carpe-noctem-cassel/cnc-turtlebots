#include "ServiceRobots/constraints/PickUp1553186320902Constraints.h"
/*PROTECTED REGION ID(ch1553186320902) ENABLED START*/
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/TaskManager.h>

#include <ttb_msgs/ServeTask.h>

#include <alica/reasoner/SimpleTerm.h>
#include <alica/reasoner/SimpleVariable.h>

#include <alica_solver_interface/SolverTerm.h>
#include <alica_solver_interface/SolverVariable.h>
#include <engine/constraintmodul/ProblemDescriptor.h>
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:PickUp
/*
 * Tasks:
 * - EP:1553250907083 : Fetch (1553250786927)
 *
 * States:
 * - Grap (1553250909207)
 * - DriveToPickUpPos (1553250909709)
 * - PickUpFail (1553250911977)
 * - DriveToObjectFail (1553250912679)
 * - PickedUp (1553250914917)
 *
 * Vars:
 * - entity (1553251224214)
 */
/*
 * RuntimeCondition - (Name): 1553251210748
 * (ConditionString):
 * Static Variables: entity
 * Domain Variables:
 *
 */
void Constraint1553251210748::getConstraint(std::shared_ptr<ProblemDescriptor> c, std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1553251210748) ENABLED START*/
    auto wm = ttb::TTBWorldModel::get();
    auto currentTask = wm->taskManager.getNextTask();
    if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PICK_UP) {
        // current task is not for picking up an object, so don't specify any problem descriptor
        auto constraint = new alica::reasoner::SimpleTerm();
        for (auto var : c->getStaticVars()) {
            auto SimpleVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(var);
            if (SimpleVar) {
                constraint->setVariable(SimpleVar, alica::reasoner::SimpleVariable::NO_VALUE);
            }
        }
        c->setConstraint(constraint);
        return;
    }

    auto constraint = new alica::reasoner::SimpleTerm();
    auto SimpleEntityVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(c->getStaticVars().at(0));
    if (SimpleEntityVar) {
        auto entity = currentTask->getInformation().entity;
        constraint->setVariable(SimpleEntityVar, entity);
    } else {
        std::cerr << "Constraint1520438401434: Variable type of Object Entity didn't fit!" << std::endl;
    }
    c->setConstraint(constraint);
    /*PROTECTED REGION END*/
}

// State: Grap
// State: DriveToPickUpPos
// State: PickUpFail
// State: DriveToObjectFail
// State: PickedUp
} // namespace alicaAutogenerated