#pragma once

#include "DomainCondition.h"
#include <engine/BasicUtilityFunction.h>
#include <engine/DefaultUtilityFunction.h>
#include <engine/UtilityFunction.h>
/*PROTECTED REGION ID(incl1454332108133) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
/*PROTECTED REGION ID(meth1454332108133) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class UtilityFunction1454332108133 : public BasicUtilityFunction
{
    shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
};
class PreCondition1454332147978 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1454332144469 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1454332146510 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1454332142376 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1454332145416 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
} // namespace alicaAutogenerated
