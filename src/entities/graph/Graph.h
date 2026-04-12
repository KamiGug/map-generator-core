#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_H

#include <memory>
#include <optional>
#include <vector>

#include "GraphOptions.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphPath;

// to be useful the graph needs to be connected and acyclic
class Graph {
   public:
    Graph(std::unique_ptr<GraphOptions> options) { this->options = std::move(options); }

    Graph() : Graph(std::make_unique<GraphOptions>()) {}

    bool addNode(std::shared_ptr<GraphNode> node, std::shared_ptr<GraphNode> parent = nullptr,
                 std::unique_ptr<GraphPathOptions> pathOptions = nullptr,
                 std::optional<bool> autoValidate = std::nullopt);

    bool addPath(std::shared_ptr<GraphNode> from, std::shared_ptr<GraphNode> to,
                 std::unique_ptr<GraphPathOptions> pathOptions = nullptr,
                 std::optional<bool> autoValidate = std::nullopt);

    const std::vector<std::shared_ptr<GraphNode>>& getNodes() const;

    const std::vector<std::shared_ptr<GraphPath>>& getPaths() const;

    inline const Graph* setAutoValidate(bool val) {
        this->options->autoValidate = val;
        return this;
    }

    std::unique_ptr<GraphOptions> options;
    bool validate();

   private:
    void _validate();
    void _validateConnected();
    void _validateAcyclic();
    bool handleAutoValidation(std::optional<bool> validate);
    std::vector<std::shared_ptr<GraphNode>> nodes;
    std::vector<std::shared_ptr<GraphPath>> paths;
};

bool operator==(const Graph& lhs, const Graph& rhs);
bool operator!=(const Graph& lhs, const Graph& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_H
