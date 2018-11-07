#pragma once

#include "DomainCondition.h"
#include <engine/BasicUtilityFunction.h>
#include <engine/DefaultUtilityFunction.h>
#include <engine/UtilityFunction.h>
/*PROTECTED REGION ID(incl1520438299583) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
/*PROTECTED REGION ID(meth1520438299583) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class UtilityFunction1520438299583 : public BasicUtilityFunction
{
    shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
};
class RunTimeCondition1520438401434 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1520438352890 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1520589543849 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1520438355739 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1520516954761 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1520518912633 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
} // namespace alicaAutogenerated
