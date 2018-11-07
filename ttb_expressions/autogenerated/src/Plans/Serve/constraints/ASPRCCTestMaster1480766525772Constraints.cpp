#include "Plans/Serve/constraints/ASPRCCTestMaster1480766525772Constraints.h"
/*PROTECTED REGION ID(ch1480766525772) ENABLED START*/
#include <ttb/TTBWorldModel.h>

#include <engine/AlicaEngine.h>
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <alica_solver_interface/SolverTerm.h>

#include <asp_commons/ASPQueryType.h>
#include <asp_commons/IASPSolver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <asp_solver_wrapper/ASPTerm.h>

#include <memory>
// Add additional using directives here
/*PROTECTED REGION END*/

using std::cout;
using std::exception;
using std::make_shared;
using namespace alica;

namespace alicaAutogenerated
{
// Plan:ASPRCCTestMaster
/*
 * Tasks:
 * - EP:1480766525774 : DefaultTask (1414681164704)
 *
 * States:
 * - NewState (1480766525773)
 * - Succ (1480766535708)
 *
 * Vars:
 * - PlanVar (1480766663869)
 */
/*
 * RuntimeCondition - (Name): NewRuntimeCondition
 * (ConditionString):
 * Static Variables: PlanVar
 * Domain Variables:
 *
 */
void Constraint1480766551805::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1480766551805) ENABLED START*/
    ttb::TTBWorldModel* wm = ttb::TTBWorldModel::get();
    auto constraint = new alica::reasoner::ASPTerm();
    // The query id has to be added to any predicate which is added to the program, naming ruleheads and facts!
    auto queryId = ((alica::reasoner::ASPSolverWrapper*) wm->getEngine()->getSolver<alica::reasoner::ASPSolverWrapper>())->getQueryCounter();
    constraint->setQueryId(queryId);
    stringstream ss;
    ss << "goalReachable(X) :- reachable(X, Y), goal(X), start(Y), room(X), room(Y).";
    constraint->setQueryRule(ss.str());
    ss.str("");
    ss << "goal(100).";
    constraint->addFact(ss.str());
    ss.str("");
    ss << "start(0).";
    constraint->addFact(ss.str());
    constraint->setProgramSection("asprccgen");
    constraint->setType(::reasoner::ASPQueryType::Variable);
    constraint->setId(1480766551805);
    c->setConstraint(constraint);
    /*PROTECTED REGION END*/
}

// State: NewState
// State: Succ
} // namespace alicaAutogenerated
