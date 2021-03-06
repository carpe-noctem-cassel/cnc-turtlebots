#include <iostream>
#include "UtilityFunctionCreator.h"

#include  "Plans/Serve/ASPFindFreeDockingStationMaster1470041057806.h"

#include  "Plans/Serve/PKVR16/SearchBoxes1481545038564.h"

#include  "Plans/Wumpus/WumpusMaster1489673406228.h"

#include  "Plans/Wumpus/InteractWIthPlayground1489673751539.h"

#include  "Plans/Serve/ServeMaster1454332108133.h"

#include  "Plans/Serve/ASPNavwoExternals1477229620130.h"

#include  "Plans/Serve/CarryBook1468494583802.h"

#include  "Plans/Serve/ASPNavwoExternalsInner1477229638868.h"

#include  "Plans/Serve/ASPMinimizePathMaster1477125857343.h"

#include  "Plans/Tests/ChargeAndSimpleDriveTest1414681057676.h"

#include  "Plans/Serve/CarryBookMaster1468493942500.h"

#include  "Plans/Serve/ASPNavigateMaster1475692538365.h"

#include  "Plans/Serve/Serve1454331313621.h"

#include  "Plans/Tests/TurtleGenericTestMaster1454329729827.h"

#include  "Plans/Serve/ASPRCCTestMaster1480766525772.h"

#include  "Plans/Wumpus/Turn1489674129255.h"

#include  "Plans/Tests/TestPOI1454329810785.h"

#include  "Plans/Serve/Charge1454331030770.h"

using namespace std;
using namespace alicaAutogenerated;
namespace alica
{

    UtilityFunctionCreator::~UtilityFunctionCreator()
    {
    }

    UtilityFunctionCreator::UtilityFunctionCreator()
    {
    }

    shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
    {
        switch (utilityfunctionConfId)
        {

            case 1470041057806:
                return make_shared<UtilityFunction1470041057806>();
                break;

            case 1481545038564:
                return make_shared<UtilityFunction1481545038564>();
                break;

            case 1489673406228:
                return make_shared<UtilityFunction1489673406228>();
                break;

            case 1489673751539:
                return make_shared<UtilityFunction1489673751539>();
                break;

            case 1454332108133:
                return make_shared<UtilityFunction1454332108133>();
                break;

            case 1477229620130:
                return make_shared<UtilityFunction1477229620130>();
                break;

            case 1468494583802:
                return make_shared<UtilityFunction1468494583802>();
                break;

            case 1477229638868:
                return make_shared<UtilityFunction1477229638868>();
                break;

            case 1477125857343:
                return make_shared<UtilityFunction1477125857343>();
                break;

            case 1414681057676:
                return make_shared<UtilityFunction1414681057676>();
                break;

            case 1468493942500:
                return make_shared<UtilityFunction1468493942500>();
                break;

            case 1475692538365:
                return make_shared<UtilityFunction1475692538365>();
                break;

            case 1454331313621:
                return make_shared<UtilityFunction1454331313621>();
                break;

            case 1454329729827:
                return make_shared<UtilityFunction1454329729827>();
                break;

            case 1480766525772:
                return make_shared<UtilityFunction1480766525772>();
                break;

            case 1489674129255:
                return make_shared<UtilityFunction1489674129255>();
                break;

            case 1454329810785:
                return make_shared<UtilityFunction1454329810785>();
                break;

            case 1454331030770:
                return make_shared<UtilityFunction1454331030770>();
                break;

            default:
                cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << endl;
                throw new exception();
                break;
        }
    }

}
