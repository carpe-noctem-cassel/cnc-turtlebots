#ifndef ASPNavigateMasterCONSTRAINT_H_
#define ASPNavigateMaster_H_
#include "engine/BasicConstraint.h"
#include <memory>

using namespace std;
using namespace alica;

namespace alica
{
    class ProblemDescriptor;
    class RunningPlan;
}

namespace alicaAutogenerated
{

    class Constraint1475692986360 : public BasicConstraint
    {
        void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan>);
    };

} /* namespace alica */

#endif /* ASPNavigateMasterCONSTRAINT_H_ */
