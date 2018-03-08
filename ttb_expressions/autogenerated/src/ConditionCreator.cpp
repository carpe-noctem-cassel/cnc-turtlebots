#include "ConditionCreator.h"

#include  "Plans/Serve/ASPFindFreeDockingStationMaster1470041057806.h"

#include  "Plans/Serve/DriveToPOI1519913821580.h"

#include  "Plans/Serve/ServeMaster1454332108133.h"

#include  "Plans/Serve/ASPNavwoExternals1477229620130.h"

#include  "Plans/Serve/CarryBook1468494583802.h"

#include  "Plans/Serve/PutDown1520511951867.h"

#include  "Plans/Serve/PickUp1520438299583.h"

#include  "Plans/Serve/ASPNavwoExternalsInner1477229638868.h"

#include  "Plans/Serve/ASPMinimizePathMaster1477125857343.h"

#include  "Plans/Serve/Search1520437018620.h"

#include  "Plans/Serve/CarryBookMaster1468493942500.h"

#include  "Plans/Serve/ASPNavigateMaster1475692538365.h"

#include  "Plans/Serve/Serve1454331313621.h"

#include  "Plans/Serve/ASPRCCTestMaster1480766525772.h"

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

            case 1519914269940:

                return make_shared<RunTimeCondition1519914269940>();

                break;

            case 1519913901102:

                return make_shared<TransitionCondition1519913901102>();

                break;

            case 1519913902356:

                return make_shared<TransitionCondition1519913902356>();

                break;

            case 1519914093807:

                return make_shared<TransitionCondition1519914093807>();

                break;

            case 1519914331734:

                return make_shared<TransitionCondition1519914331734>();

                break;

            case 1519914333760:

                return make_shared<TransitionCondition1519914333760>();

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

            case 1520438401434:

                return make_shared<RunTimeCondition1520438401434>();

                break;

            case 1520438352890:

                return make_shared<TransitionCondition1520438352890>();

                break;

            case 1520438355739:

                return make_shared<TransitionCondition1520438355739>();

                break;

            case 1520516954761:

                return make_shared<TransitionCondition1520516954761>();

                break;

            case 1520518912633:

                return make_shared<TransitionCondition1520518912633>();

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

            case 1520437448508:

                return make_shared<RunTimeCondition1520437448508>();

                break;

            case 1520438036937:

                return make_shared<TransitionCondition1520438036937>();

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

            case 1520511978036:

                return make_shared<TransitionCondition1520511978036>();

                break;

            case 1520511979544:

                return make_shared<TransitionCondition1520511979544>();

                break;

            case 1480766551805:

                return make_shared<RunTimeCondition1480766551805>();

                break;

            case 1480766547208:

                return make_shared<TransitionCondition1480766547208>();

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
