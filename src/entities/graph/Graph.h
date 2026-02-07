#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_H

#include <memory>
#include <optional>
#include <vector>

#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphPath;

// to be useful the graph needs to be connected and acyclic
class Graph {
   public:
    Graph(bool autoValidate = true);

    // ~Graph();

    bool addNode(std::shared_ptr<GraphNode> node, std::shared_ptr<GraphNode> parent = nullptr,
                 std::unique_ptr<GraphPathOptions> pathOptions = nullptr,
                 std::optional<bool> autoValidate = std::nullopt);

    bool addPath(std::shared_ptr<GraphNode> from, std::shared_ptr<GraphNode> to,
                 std::unique_ptr<GraphPathOptions> pathOptions = nullptr,
                 std::optional<bool> autoValidate = std::nullopt);

    const std::vector<std::shared_ptr<GraphNode>>& getNodes() const;

    const std::vector<std::shared_ptr<GraphPath>>& getPaths() const;

    bool validate();

   private:
    std::vector<std::shared_ptr<GraphNode>> nodes;
    std::vector<std::shared_ptr<GraphPath>> paths;
    bool autoValidate;
};

bool operator==(const Graph& lhs, const Graph& rhs);
bool operator!=(const Graph& lhs, const Graph& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_H
