#include "ConstraintCreator.h"
#include <iostream>

#include  "Plans/Serve/constraints/ASPFindFreeDockingStationMaster1470041057806Constraints.h"

#include  "Plans/Serve/PKVR16/constraints/SearchBoxes1481545038564Constraints.h"

#include  "Plans/Serve/PKVR16/constraints/CollectBoxes1481544845570Constraints.h"

#include  "Plans/Serve/constraints/ServeMaster1454332108133Constraints.h"

#include  "Plans/Serve/constraints/ASPNavwoExternals1477229620130Constraints.h"

#include  "Plans/Serve/constraints/CarryBook1468494583802Constraints.h"

#include  "Plans/Serve/constraints/ASPNavwoExternalsInner1477229638868Constraints.h"

#include  "Plans/Serve/constraints/ASPMinimizePathMaster1477125857343Constraints.h"

#include  "Plans/Tests/constraints/ChargeAndSimpleDriveTest1414681057676Constraints.h"

#include  "Plans/Serve/constraints/CarryBookMaster1468493942500Constraints.h"

#include  "Plans/Serve/constraints/ASPNavigateMaster1475692538365Constraints.h"

#include  "Plans/Serve/constraints/Serve1454331313621Constraints.h"

#include  "Plans/Tests/constraints/TurtleGenericTestMaster1454329729827Constraints.h"

#include  "Plans/Tests/constraints/TestPOI1454329810785Constraints.h"

#include  "Plans/Serve/constraints/Charge1454331030770Constraints.h"

using namespace std;
using namespace alicaAutogenerated;

namespace alica
{

    ConstraintCreator::ConstraintCreator()
    {
    }

    ConstraintCreator::~ConstraintCreator()
    {
    }

    shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(long constraintConfId)
    {
        switch (constraintConfId)
        {

            case 1470042926317:
                return make_shared<Constraint1470042926317>();
                break;

            case 1477229706852:
                return make_shared<Constraint1477229706852>();
                break;

            case 1468495216221:
                return make_shared<Constraint1468495216221>();
                break;

            case 1477229712321:
                return make_shared<Constraint1477229712321>();
                break;

            case 1477125906086:
                return make_shared<Constraint1477125906086>();
                break;

            case 1475692986360:
                return make_shared<Constraint1475692986360>();
                break;

            default:
                cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << endl;
                throw new exception();
                break;
        }
    }

}
