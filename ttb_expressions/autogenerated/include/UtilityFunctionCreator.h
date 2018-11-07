#pragma once

#include <engine/IUtilityCreator.h>
#include <memory>

namespace alica
{

class UtilityFunctionCreator : public IUtilityCreator
{
public:
    virtual ~UtilityFunctionCreator();
    UtilityFunctionCreator();
    shared_ptr<BasicUtilityFunction> createUtility(long utilityfunctionConfId);
};

} /* namespace alica */
