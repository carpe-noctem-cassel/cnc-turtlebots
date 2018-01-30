#include "Plans/Serve/constraints/ASPNavigateMaster1475692538365Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1475692538365) ENABLED START*/
//Add additional using directives here
#include <asp_solver_wrapper/ASPTerm.h>
#include <asp_commons/IASPSolver.h>
#include <asp_commons/ASPQueryType.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <SolverType.h>
#include <engine/AlicaEngine.h>
#include "engine/constraintmodul/SolverTerm.h"
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <memory>
#include "TTBWorldModel.h"
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:ASPNavigateMaster

    /*		
     * Tasks: 
     * - EP:1475692538367 : DefaultTask (1414681164704)
     *
     * States:
     * - Navigate (1475692538366)
     * - Stop (1476366084811)
     *
     * Vars:				
     * - NavMasterVar (1475698052801) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [NavMasterVar]
     * Domain Variables:

     */
    void Constraint1475692986360::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1475692986360) ENABLED START*/
        ttb::TTBWorldModel* wm = ttb::TTBWorldModel::get();
        auto constraint = make_shared<alica::reasoner::ASPTerm>(-1);
        //The query id has to be added to any predicate which is added to the program, naming ruleheads and facts!
        auto queryId = ((alica::reasoner::ASPSolverWrapper*)wm->getEngine()->getSolver(SolverType::ASPSOLVER))->getQueryCounter();
        constraint->setQueryId(queryId);
        stringstream ss;
        ss << "goalReachable(X) :- reachable(X, Y), goal(X), start(Y), room(X), room(Y).";
        constraint->setQueryRule(ss.str());
        ss.str("");
//        ss << "multiRuleWorks(X, " << queryId << ") :- goal(r1405B, " << queryId << "), room(X).";
//        constraint->addRule(ss.str());
//        ss.str("");
        ss << "goal(r1405B).";
        constraint->addFact(ss.str());
        ss.str("");
        ss << "start(r1411).";
        constraint->addFact(ss.str());
        constraint->setProgramSection("distributedSystemsRoomsExternal");
        constraint->setType(::reasoner::ASPQueryType::Variable);
        constraint->setId(1475692986360);
        //TODO fix after adding asp to topological model
//        constraint->setExternals(wm->doors.getDoors());
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: Navigate

// State: Navigate

// State: Stop

// State: Stop

}
