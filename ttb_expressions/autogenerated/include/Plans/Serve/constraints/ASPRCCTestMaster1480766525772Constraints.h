#pragma once

#include <engine/BasicConstraint.h>
#include <iostream>
#include <memory>

using std::cout;
using std::exception;
using std::make_shared;
using std::shared_ptr;
using namespace alica;

namespace alica
{
class ProblemDescriptor;
class RunningPlan;
} // namespace alica

namespace alicaAutogenerated
{

class Constraint1480766551805 : public BasicConstraint
{
    void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp);
};
} // namespace alicaAutogenerated
