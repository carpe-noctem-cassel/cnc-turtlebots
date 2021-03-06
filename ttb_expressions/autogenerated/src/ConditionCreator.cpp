#include "ConditionCreator.h"

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

using namespace alicaAutogenerated;
namespace alica
{

    ConditionCreator::ConditionCreator()
    {
    }
    ConditionCreator::~ConditionCreator()
    {
    }

    shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
    {
        switch (conditionConfId)
        {

            case 1470042926317:

                return make_shared<RunTimeCondition1470042926317>();

                break;

            case 1470041208746:

                return make_shared<TransitionCondition1470041208746>();

                break;

            case 1470042249132:

                return make_shared<TransitionCondition1470042249132>();

                break;

            case 1486383886372:

                return make_shared<TransitionCondition1486383886372>();

                break;

            case 1489673564931:

                return make_shared<TransitionCondition1489673564931>();

                break;

            case 1489673638984:

                return make_shared<TransitionCondition1489673638984>();

                break;

            case 1489673686543:

                return make_shared<TransitionCondition1489673686543>();

                break;

            case 1489674024580:

                return make_shared<TransitionCondition1489674024580>();

                break;

            case 1489674025736:

                return make_shared<TransitionCondition1489674025736>();

                break;

            case 1454332142376:

                return make_shared<TransitionCondition1454332142376>();

                break;

            case 1454332144469:

                return make_shared<TransitionCondition1454332144469>();

                break;

            case 1454332145416:

                return make_shared<TransitionCondition1454332145416>();

                break;

            case 1454332146510:

                return make_shared<TransitionCondition1454332146510>();

                break;

            case 1454332147978:

                return make_shared<TransitionCondition1454332147978>();

                break;

            case 1477229706852:

                return make_shared<RunTimeCondition1477229706852>();

                break;

            case 1477229633243:

                return make_shared<TransitionCondition1477229633243>();

                break;

            case 1477229680268:

                return make_shared<TransitionCondition1477229680268>();

                break;

            case 1468495216221:

                return make_shared<RunTimeCondition1468495216221>();

                break;

            case 1468919500674:

                return make_shared<PreCondition1468919500674>();

                break;

            case 1468919192856:

                return make_shared<TransitionCondition1468919192856>();

                break;

            case 1477229712321:

                return make_shared<RunTimeCondition1477229712321>();

                break;

            case 1479298302100:

                return make_shared<TransitionCondition1479298302100>();

                break;

            case 1477125906086:

                return make_shared<RunTimeCondition1477125906086>();

                break;

            case 1414681505635:

                return make_shared<TransitionCondition1414681505635>();

                break;

            case 1447068020434:

                return make_shared<TransitionCondition1447068020434>();

                break;

            case 1447068022583:

                return make_shared<TransitionCondition1447068022583>();

                break;

            case 1447068025867:

                return make_shared<TransitionCondition1447068025867>();

                break;

            case 1447068027882:

                return make_shared<TransitionCondition1447068027882>();

                break;

            case 1447919930987:

                return make_shared<TransitionCondition1447919930987>();

                break;

            case 1447958162066:

                return make_shared<TransitionCondition1447958162066>();

                break;

            case 1447958165046:

                return make_shared<TransitionCondition1447958165046>();

                break;

            case 1447958174005:

                return make_shared<TransitionCondition1447958174005>();

                break;

            case 1469016825041:

                return make_shared<TransitionCondition1469016825041>();

                break;

            case 1475692986360:

                return make_shared<RunTimeCondition1475692986360>();

                break;

            case 1476366089212:

                return make_shared<TransitionCondition1476366089212>();

                break;

            case 1454331384091:

                return make_shared<TransitionCondition1454331384091>();

                break;

            case 1454331385501:

                return make_shared<TransitionCondition1454331385501>();

                break;

            case 1454331503425:

                return make_shared<TransitionCondition1454331503425>();

                break;

            case 1486383768270:

                return make_shared<TransitionCondition1486383768270>();

                break;

            case 1486383787970:

                return make_shared<TransitionCondition1486383787970>();

                break;

            case 1486383790747:

                return make_shared<TransitionCondition1486383790747>();

                break;

            case 1454329746996:

                return make_shared<TransitionCondition1454329746996>();

                break;

            case 1454329748126:

                return make_shared<TransitionCondition1454329748126>();

                break;

            case 1480766551805:

                return make_shared<RunTimeCondition1480766551805>();

                break;

            case 1480766547208:

                return make_shared<TransitionCondition1480766547208>();

                break;

            case 1489674258430:

                return make_shared<TransitionCondition1489674258430>();

                break;

            case 1489674311741:

                return make_shared<TransitionCondition1489674311741>();

                break;

            case 1489674364780:

                return make_shared<TransitionCondition1489674364780>();

                break;

            case 1489674399440:

                return make_shared<TransitionCondition1489674399440>();

                break;

            case 1489746556848:

                return make_shared<TransitionCondition1489746556848>();

                break;

            case 1489746558803:

                return make_shared<TransitionCondition1489746558803>();

                break;

            case 1489746560602:

                return make_shared<TransitionCondition1489746560602>();

                break;

            case 1489746562418:

                return make_shared<TransitionCondition1489746562418>();

                break;

            case 1454329835328:

                return make_shared<TransitionCondition1454329835328>();

                break;

            case 1454329836408:

                return make_shared<TransitionCondition1454329836408>();

                break;

            case 1454331127179:

                return make_shared<TransitionCondition1454331127179>();

                break;

            case 1454331145639:

                return make_shared<TransitionCondition1454331145639>();

                break;

            default:
                cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
                throw new exception();
                break;
        }
    }
}
