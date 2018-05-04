#pragma once

#include "DomainCondition.h"
#include <engine/BasicUtilityFunction.h>
#include <engine/DefaultUtilityFunction.h>
#include <engine/UtilityFunction.h>
/*PROTECTED REGION ID(incl1475692538365) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
/*PROTECTED REGION ID(meth1475692538365) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class UtilityFunction1475692538365 : public BasicUtilityFunction
{
    shared_ptr<UtilityFunction> getUtilityFunction(Plan *plan);
};
class RunTimeCondition1475692986360 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
class PreCondition1476366089212 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};
} /* namespace alica */
