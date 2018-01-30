#pragma once

#include <map>
#include <memory>
#include <vector>

#define TP_DEBUG

namespace ttb
{
namespace wm
{
class Door;
class Room;
class Area;
namespace pathPlanning
{
class TopologicalModel;
class TopologicalPathPlanner
{
  public:
    TopologicalPathPlanner(TopologicalModel *ds);
    virtual ~TopologicalPathPlanner();
    /*
     * Returns a vector of Areas
     * First Area contains start room
     * Last Area contains goal room
     */
    std::vector<std::shared_ptr<ttb::wm::Area>> plan(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal);
    /*
     * Returns a vector of Doors
     * First Door is start of path
     * Last Door is connected to the goal Area
     */
    std::vector<std::shared_ptr<ttb::wm::Door>> planInsideArea(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Area> goal);

  private:
    TopologicalModel *topologicalModel;
    bool areaBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Area>> &fringe,
                           std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>> &visited, std::shared_ptr<ttb::wm::Area> goal);
    std::shared_ptr<ttb::wm::Room> roomBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Room>> &fringe,
                                                     std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>> &visited,
                                                     std::shared_ptr<Area> goal);
};
}
} /* namespace wm */
} /* namespace ttb */
