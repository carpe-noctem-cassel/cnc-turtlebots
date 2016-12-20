#include "Plans/Serve/constraints/CarryBook1468494583802Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1468494583802) ENABLED START*/
#include <alica_asp_solver/ASPTerm.h>
#include <alica_asp_solver/ASPSolver.h>
#include <alica_asp_solver/ASPQueryType.h>
#include <SolverType.h>
#include <engine/AlicaEngine.h>
#include "engine/constraintmodul/SolverTerm.h"
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <memory>
#include "TTBWorldModel.h"
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
     * - NewSuccessState (1468919156738)
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
    void Constraint1468495216221::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1468495216221) ENABLED START*/
        ttb::TTBWorldModel* wm = ttb::TTBWorldModel::get();
        auto constraint = make_shared<alica::reasoner::ASPTerm>();
        //The query id has to be added to any predicate which is added to the program, naming ruleheads and facts!
        auto queryId = ((alica::reasoner::ASPSolver*)wm->getEngine()->getSolver(SolverType::ASPSOLVER))->getQueryCounter();
        constraint->setQueryId(queryId);
        stringstream ss;
        ss << "freeFairyTailBook(X, " << queryId << ") :- book(X), genre(fairyTail), bookGenre(X, fairyTail), not on(X,Y) : agent(Y).";
        constraint->setRule(ss.str());
        constraint->setProgramSection("bookExample");
        constraint->setType(alica::reasoner::ASPQueryType::Variable);
        constraint->setId(1468495216221);
        constraint->setExternals(wm->doors.getDoors());
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: CarryBook

// State: CarryBook

// State: NewSuccessState

// State: NewSuccessState

}
