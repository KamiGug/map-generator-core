#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H

#include "AbstractGraphBuilder.h"
#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GenerateTreeBuilder : public AbstractGraphBuilder {
   public:
    GenerateTreeBuilder();
    Graph* build() override;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H
