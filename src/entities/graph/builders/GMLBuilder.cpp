#include "GMLBuilder.h"

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

GMLBuilder::GMLBuilder(std::vector<std::string>& graphDefinition) { this->graphDefinition = graphDefinition; }
// TODO: implement
Graph* GMLBuilder::build() {
    Graph* graph = new Graph();

    return graph;
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
