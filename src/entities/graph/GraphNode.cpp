#include "GraphNode.h"

#include <algorithm>
#include <memory>

#include "entities/graph/GraphPath.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

GraphNode::GraphNode(std::shared_ptr<Biome> biome) { this->biome = biome; }

void GraphNode::addPath(std::shared_ptr<GraphPath> path, bool validate) {
    if (path->isFrom(this)) {
        if (!validate || std::find(pathsFrom.begin(), pathsFrom.end(), path) == pathsFrom.end()) {
            pathsFrom.push_back(path);
        }
        // TODO: consider throwing on else;
    }
    if (path->isTo(this)) {
        if (!validate || std::find(pathsTo.begin(), pathsTo.end(), path) == pathsTo.end()) {
            pathsTo.push_back(path);
        }
        // TODO: consider throwing on else;
    }
}

bool operator==(const GraphNode& lhs, const GraphNode& rhs) {
    if (*(lhs.getBiome()) != *(rhs.getBiome())) return false;
    // TODO: decide whether to check paths
    return true;
}

bool operator!=(const GraphNode& lhs, const GraphNode& rhs) { return !(lhs == rhs); }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
