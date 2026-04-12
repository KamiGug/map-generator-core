#include "GenerateTreeBuilder.h"

#include <memory>

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

GenerateTreeBuilder::GenerateTreeBuilder() {}
// TODO: implement
std::unique_ptr<Graph> GenerateTreeBuilder::build(std::unique_ptr<GraphOptions> options) {
    return std::make_unique<Graph>(std::move(options));
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
