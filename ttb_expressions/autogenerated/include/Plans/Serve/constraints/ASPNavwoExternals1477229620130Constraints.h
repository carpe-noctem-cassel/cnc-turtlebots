#ifndef ASPNavwoExternalsCONSTRAINT_H_
#define ASPNavwoExternals_H_
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

    class Constraint1477229706852 : public BasicConstraint
    {
        void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan>);
    };

} /* namespace alica */

#endif /* ASPNavwoExternalsCONSTRAINT_H_ */
