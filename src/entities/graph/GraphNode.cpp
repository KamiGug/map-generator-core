#include "GraphNode.h"

#include <algorithm>

#include "entities/graph/GraphPath.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

GraphNode::GraphNode(Biome* biome) { this->biome = biome; }
const std::vector<std::shared_ptr<GraphPath>> GraphNode::getPaths() const { return this->paths; }

void GraphNode::addPath(std::shared_ptr<GraphPath> path) {
    if (std::find(paths.begin(), paths.end(), path) != paths.end()) {
        // TODO: consider throwing
        return;
    }
    if (path->isFrom(this)) {
        paths.push_back(path);
    }
    // TODO: consider throwing on else
}

bool operator==(const GraphNode& lhs, const GraphNode& rhs) {
    if (*(lhs.getBiome()) != *(rhs.getBiome())) return false;
    // TODO: decide whether to check paths
    return true;
}

bool operator!=(const GraphNode& lhs, const GraphNode& rhs) { return !(lhs == rhs); }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
