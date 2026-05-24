#ifndef MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_STEP_H
#define MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_STEP_H

#include <memory>

#include "entities/graph/Graph.h"
#include "steps/graphMapping/result/PhysicalBiome.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class AbstractGraphPlacementStep {
   public:
    inline AbstractGraphPlacementStep(std::shared_ptr<Entities::Graph> graph) { this->graph = graph; }

    virtual ~AbstractGraphPlacementStep() = default;

    virtual std::vector<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Steps::PhysicalBiome>> transform() = 0;

   protected:
    std::shared_ptr<Entities::Graph> graph;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_STEP_H
