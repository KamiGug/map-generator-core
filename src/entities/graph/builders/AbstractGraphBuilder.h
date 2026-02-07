#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class AbstractGraphBuilder {
   public:
    virtual Graph* build() = 0;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_H
