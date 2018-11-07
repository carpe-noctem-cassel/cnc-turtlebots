#include "ConstraintCreator.h"

#include "Plans/Serve/constraints/ASPFindFreeDockingStationMaster1470041057806Constraints.h"
#include "Plans/Serve/constraints/ASPMinimizePathMaster1477125857343Constraints.h"
#include "Plans/Serve/constraints/ASPNavigateMaster1475692538365Constraints.h"
#include "Plans/Serve/constraints/ASPNavwoExternals1477229620130Constraints.h"
#include "Plans/Serve/constraints/ASPNavwoExternalsInner1477229638868Constraints.h"
#include "Plans/Serve/constraints/ASPRCCTestMaster1480766525772Constraints.h"
#include "Plans/Serve/constraints/CarryBook1468494583802Constraints.h"
#include "Plans/Serve/constraints/CarryBookMaster1468493942500Constraints.h"
#include "Plans/Serve/constraints/Charge1454331030770Constraints.h"
#include "Plans/Serve/constraints/DriveToPOI1519913821580Constraints.h"
#include "Plans/Serve/constraints/PickUp1520438299583Constraints.h"
#include "Plans/Serve/constraints/PutDown1520511951867Constraints.h"
#include "Plans/Serve/constraints/Search1520437018620Constraints.h"
#include "Plans/Serve/constraints/Serve1454331313621Constraints.h"
#include "Plans/Serve/constraints/ServeMaster1454332108133Constraints.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::make_shared;
using std::shared_ptr;
using namespace alicaAutogenerated;

namespace alica
{

ConstraintCreator::ConstraintCreator() {}

ConstraintCreator::~ConstraintCreator() {}

shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(long constraintConfId)
{
    switch (constraintConfId) {
    case 1468495216221:
        return make_shared<Constraint1468495216221>();
        break;
    case 1470042926317:
        return make_shared<Constraint1470042926317>();
        break;
    case 1475692986360:
        return make_shared<Constraint1475692986360>();
        break;
    case 1477125906086:
        return make_shared<Constraint1477125906086>();
        break;
    case 1477229706852:
        return make_shared<Constraint1477229706852>();
        break;
    case 1477229712321:
        return make_shared<Constraint1477229712321>();
        break;
    case 1480766551805:
        return make_shared<Constraint1480766551805>();
        break;
    case 1519914269940:
        return make_shared<Constraint1519914269940>();
        break;
    case 1520437448508:
        return make_shared<Constraint1520437448508>();
        break;
    case 1520438401434:
        return make_shared<Constraint1520438401434>();
        break;
    case 1520850075314:
        return make_shared<Constraint1520850075314>();
        break;
    default:
        cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << endl;
        throw new exception();
        break;
    }
}
} // namespace alica
