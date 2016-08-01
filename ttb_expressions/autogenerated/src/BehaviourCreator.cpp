using namespace std;

#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"

#include  "Plans/Behaviours/Stop.h"

#include  "Plans/Behaviours/DriveToPOI.h"

#include  "Plans/Behaviours/SimpleDrive.h"

#include  "Plans/Behaviours/SearchForDockingStationAsp.h"

#include  "Plans/Behaviours/Rotate.h"

#include  "Plans/Behaviours/ChargingDefault.h"

#include  "Plans/Behaviours/Carry.h"

#include  "Plans/Behaviours/SearchDockingStation.h"

namespace alica
{

    BehaviourCreator::BehaviourCreator()
    {
    }

    BehaviourCreator::~BehaviourCreator()
    {
    }

    shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourConfId)
    {
        switch (behaviourConfId)
        {

            case 1414681278745:

                return make_shared<Stop>();
                break;

            case 1454329864420:

            case 1454329905072:

            case 1454329918634:

            case 1454330438527:

                return make_shared<DriveToPOI>();
                break;

            case 1432735473356:

                return make_shared<SimpleDrive>();
                break;

            case 1470041828429:

                return make_shared<SearchForDockingStationAsp>();
                break;

            case 1447068225787:

                return make_shared<Rotate>();
                break;

            case 1447958132701:

                return make_shared<ChargingDefault>();
                break;

            case 1468494631985:

                return make_shared<Carry>();
                break;

            case 1414681446065:

                return make_shared<SearchDockingStation>();
                break;

            default:
                cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << endl;
                throw new exception();
                break;
        }
    }
}
