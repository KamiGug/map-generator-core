#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H

#include <memory>
#include <vector>

#include "GraphPath.h"
#include "entities/Biome.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphNode {
   public:
    GraphNode(Biome* biome);
    inline ~GraphNode() {
        if (biome != nullptr) delete biome;
    }
    const std::vector<std::shared_ptr<GraphPath>> getPaths() const;
    const Biome* getBiome() const { return this->biome; };
    void addPath(std::shared_ptr<GraphPath> path);

   private:
    Biome* biome = nullptr;
    std::vector<std::shared_ptr<GraphPath>> paths;
};

bool operator==(const GraphNode& lhs, const GraphNode& rhs);
bool operator!=(const GraphNode& lhs, const GraphNode& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H
