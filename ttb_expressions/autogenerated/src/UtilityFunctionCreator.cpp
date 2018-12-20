#include "UtilityFunctionCreator.h"
#include "Plans/Serve/ASPFindFreeDockingStationMaster1470041057806.h"
#include "Plans/Serve/ASPMinimizePathMaster1477125857343.h"
#include "Plans/Serve/ASPNavigateMaster1475692538365.h"
#include "Plans/Serve/ASPNavwoExternals1477229620130.h"
#include "Plans/Serve/ASPNavwoExternalsInner1477229638868.h"
#include "Plans/Serve/ASPRCCTestMaster1480766525772.h"
#include "Plans/Serve/CarryBook1468494583802.h"
#include "Plans/Serve/CarryBookMaster1468493942500.h"
#include "Plans/Serve/Charge1454331030770.h"
#include "Plans/Serve/DriveToPOI1519913821580.h"
#include "Plans/Serve/PickUp1520438299583.h"
#include "Plans/Serve/PutDown1520511951867.h"
#include "Plans/Serve/Search1520437018620.h"
#include "Plans/Serve/Serve1454331313621.h"
#include "Plans/Serve/ServeMaster1454332108133.h"
#include "Plans/Serve/HackedPlan1.h"
#include <iostream>

using std::cout;
using std::exception;
using std::make_shared;
using namespace alicaAutogenerated;

namespace alica
{

UtilityFunctionCreator::~UtilityFunctionCreator() {}

UtilityFunctionCreator::UtilityFunctionCreator() {}

shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
{
    switch (utilityfunctionConfId) {
    case 1454331030770:
        return make_shared<UtilityFunction1454331030770>();
        break;
    case 1454331313621:
        return make_shared<UtilityFunction1454331313621>();
        break;
    case 1454332108133:
        return make_shared<UtilityFunction1454332108133>();
        break;
    case 1468493942500:
        return make_shared<UtilityFunction1468493942500>();
        break;
    case 1468494583802:
        return make_shared<UtilityFunction1468494583802>();
        break;
    case 1470041057806:
        return make_shared<UtilityFunction1470041057806>();
        break;
    case 1475692538365:
        return make_shared<UtilityFunction1475692538365>();
        break;
    case 1477125857343:
        return make_shared<UtilityFunction1477125857343>();
        break;
    case 1477229620130:
        return make_shared<UtilityFunction1477229620130>();
        break;
    case 1477229638868:
        return make_shared<UtilityFunction1477229638868>();
        break;
    case 1480766525772:
        return make_shared<UtilityFunction1480766525772>();
        break;
    case 1519913821580:
        return make_shared<UtilityFunction1519913821580>();
        break;
    case 1520437018620:
        return make_shared<UtilityFunction1520437018620>();
        break;
    case 1520438299583:
        return make_shared<UtilityFunction1520438299583>();
        break;
    case 1520511951867:
        return make_shared<UtilityFunction1520511951867>();
        break;
    case 1:
        return make_shared<UtilityFunction1>();
        break;
    default:
        std::cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << std::endl;
        throw new exception();
        break;
    }
}
} // namespace alica
