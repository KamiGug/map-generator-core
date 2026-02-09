#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H

#include <memory>
#include <vector>

#include "GraphPath.h"
#include "entities/Biome.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphNode {
   public:
    GraphNode(std::shared_ptr<Biome> biome);
    inline const std::vector<std::shared_ptr<GraphPath>>& getPathsFrom() const { return pathsFrom; }
    inline const std::vector<std::shared_ptr<GraphPath>>& getPathsTo() const { return pathsTo; }
    const std::shared_ptr<Biome> getBiome() const { return this->biome; };
    void addPath(std::shared_ptr<GraphPath> path, bool validate = true);

   private:
    std::shared_ptr<Biome> biome;
    std::vector<std::shared_ptr<GraphPath>> pathsFrom;
    std::vector<std::shared_ptr<GraphPath>> pathsTo;
};

bool operator==(const GraphNode& lhs, const GraphNode& rhs);
bool operator!=(const GraphNode& lhs, const GraphNode& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_NODE_H
