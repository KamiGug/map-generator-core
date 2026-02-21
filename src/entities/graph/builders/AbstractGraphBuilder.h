#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H

#include <memory>

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class AbstractGraphBuilder {
   public:
    virtual std::unique_ptr<Graph> build() = 0;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H
