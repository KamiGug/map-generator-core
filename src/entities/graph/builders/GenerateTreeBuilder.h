#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H

#include <memory>

#include "AbstractGraphBuilder.h"
#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GenerateTreeBuilder : public AbstractGraphBuilder {
   public:
    GenerateTreeBuilder();
    std::unique_ptr<Graph> build(std::unique_ptr<GraphOptions> = nullptr) override;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TREE_GENERATOR_H
