#ifndef ASPNavwoExternalsInnerCONSTRAINT_H_
#define ASPNavwoExternalsInner_H_
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

    class Constraint1477229712321 : public BasicConstraint
    {
        void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp);
    };

} /* namespace alica */

#endif /* ASPNavwoExternalsInnerCONSTRAINT_H_ */
