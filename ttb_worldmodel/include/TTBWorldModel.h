#pragma once

//#include "WumpusData.h"
#include "Doors.h"
#include "EventTrigger.h"
#include "LogicalCameraData.h"
#include "RawSensorData.h"
#include "SystemConfig.h"
#include "TaskManager.h"
#include "EventTrigger.h"
#include "ttb_poi/TTBPointOfInterests.h"

#include <supplementary/WorldModel.h>
#include <supplementary/InfoBuffer.h>

#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <tuple>

namespace supplementary
{
class SystemConfig;
}

namespace alica
{
class AlicaEngine;
}

namespace ttb
{
class WrappedMessageHandler;

class TTBWorldModel : public supplementary::WorldModel
{
  public:
    virtual ~TTBWorldModel();
    static TTBWorldModel *get(); /**< Singleton Getter */

    supplementary::InfoTime getTime();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::LogicalCameraData logicalCameraData;
    wm::TaskManager taskManager;
    wm::TTBPointOfInterests pois;
    wm::Doors doors;
    //WumpusData wumpusData;

  private:
    TTBWorldModel(); /**< Private Singleton Constructor */
    mutex wmMutex;
};

} /* namespace ttb */
