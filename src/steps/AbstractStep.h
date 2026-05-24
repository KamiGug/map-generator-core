#ifndef MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H
#define MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H

#include <memory>

#include "entities/containers/Space2D.h"
#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class AbstractStep {
   public:
    inline AbstractStep(std::shared_ptr<Entities::Space2D> space, std::shared_ptr<Entities::Graph> graph) {
        this->space = space;
        this->graph = graph;
    }
    virtual ~AbstractStep() = default;
    void virtual transform() = 0;

   protected:
    std::shared_ptr<Entities::Space2D> space;
    std::shared_ptr<Entities::Graph> graph;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H
