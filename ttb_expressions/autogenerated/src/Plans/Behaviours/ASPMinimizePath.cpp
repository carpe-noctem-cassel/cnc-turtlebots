using namespace std;
#include "Plans/Behaviours/ASPMinimizePath.h"

/*PROTECTED REGION ID(inccpp1477125924367) ENABLED START*/ //Add additional includes here
#include "SolverType.h"
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1477125924367) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    ASPMinimizePath::ASPMinimizePath() :
            DomainBehaviour("ASPMinimizePath")
    {
        /*PROTECTED REGION ID(con1477125924367) ENABLED START*/ //Add additional options here
        this->query = make_shared < alica::ConstraintQuery > (this->wm->getEngine());
        /*PROTECTED REGION END*/
    }
    ASPMinimizePath::~ASPMinimizePath()
    {
        /*PROTECTED REGION ID(dcon1477125924367) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void ASPMinimizePath::run(void* msg)
    {
        /*PROTECTED REGION ID(run1477125924367) ENABLED START*/ //Add additional options here
        std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
        std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
        cout << "ASPMinimizePath: Measured Solving and Grounding Time: " << std::chrono::duration_cast
                < chrono::milliseconds > (end - start).count() << " ms" << endl;
        if (result.size() > 0 && result.at(0).size() > 0)
        {
            cout << "ASPMinimizePath: ASP result found!" << endl;
            cout << "\tResult contains the predicates: " << endl;
            cout << "\t\t";
            for (int i = 0; i < result.size(); i++)
            {
                for (int j = 0; j < result.at(i).size(); j++)
                {
                    cout << result.at(i).at(j) << " ";
                }
            }
            cout << endl;

        }
        else
        {
            cout << "ASPMinimizePath: no result found!" << endl;
        }
        /*PROTECTED REGION END*/
    }
    void ASPMinimizePath::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1477125924367) ENABLED START*/ //Add additional options here
        query->clearStaticVariables();
        query->addVariable(getVariablesByName("MinVar"));
        result.clear();
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1477125924367) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */