using namespace std;
#include "Plans/Behaviours/ASPNavigation.h"

/*PROTECTED REGION ID(inccpp1475693360605) ENABLED START*/ //Add additional includes here
#include <TTBWorldModel.h>
#include "SolverType.h"
#include "actionlib/client/simple_action_client.h"
#include "move_base_msgs/MoveBaseAction.h"
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1475693360605) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	ASPNavigation::ASPNavigation() :
			DomainBehaviour("ASPNavigation")
	{
		/*PROTECTED REGION ID(con1475693360605) ENABLED START*/ //Add additional options here
		this->query = make_shared<alica::ConstraintQuery>(this->wm->getEngine());
		/*PROTECTED REGION END*/
	}
	ASPNavigation::~ASPNavigation()
	{
		/*PROTECTED REGION ID(dcon1475693360605) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void ASPNavigation::run(void* msg)
	{
		/*PROTECTED REGION ID(run1475693360605) ENABLED START*/ //Add additional options here
		std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
		query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
		std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
		cout << "ASPNavigation: Measured Solving and Grounding Time: "
				<< std::chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
		if (result.size() > 0)
		{
			cout << "SearchForDockingStationAsp: ASP result found!" << endl;
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

		stringstream ss;
		ss << result.at(0).at(0);
		shared_ptr<ttb::POI> dockingStation = this->wm->pois.getPOIByName(extractPOI(ss.str()));

		/*PROTECTED REGION END*/
	}
	void ASPNavigation::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1475693360605) ENABLED START*/ //Add additional options here
		query->clearStaticVariables();
		query->addVariable(getVariablesByName("SearchVar"));
		result.clear();
		/*PROTECTED REGION END*/
	}
	/*PROTECTED REGION ID(methods1475693360605) ENABLED START*/ //Add additional methods here
	string ASPNavigation::extractPOI(string aspPredicate)
	{
		size_t start = aspPredicate.find("(");
		size_t end = aspPredicate.find(")", start);
		string ret = aspPredicate.substr(start + 1, end - start - 1);
		return ret;
	}
/*PROTECTED REGION END*/
} /* namespace alica */
