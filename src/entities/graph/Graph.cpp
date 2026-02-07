#include "Graph.h"

#include <memory>

#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPath.h"
#include "entities/graph/GraphPathOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {
Graph::Graph(bool autoValidate) { this->autoValidate = autoValidate; }

bool Graph::addNode(std::shared_ptr<GraphNode> node, std::shared_ptr<GraphNode> parent,
                    std::unique_ptr<GraphPathOptions> pathOptions, std::optional<bool> autoValidate) {
    this->nodes.push_back(node);
    if (parent != nullptr) {
        if (pathOptions == nullptr) pathOptions = std::unique_ptr<GraphPathOptions>();
        this->addPath(parent, node, std::move(pathOptions));
    }

    return !autoValidate.value_or(this->autoValidate) && this->validate();
}

bool Graph::addPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end,
                    std::unique_ptr<GraphPathOptions> pathOptions, std::optional<bool> autoValidate) {
    if (pathOptions == nullptr) pathOptions = std::unique_ptr<GraphPathOptions>();
    std::shared_ptr<GraphPath> path =
        // TODO: change GraphNode* to std::shared_ptr
        std::make_shared<GraphPath>(start, end, std::move(pathOptions));
    start->addPath(path);
    if (path->isBidirectional()) end->addPath(path);
    this->paths.push_back(path);
    return !autoValidate.value_or(this->autoValidate) && this->validate();
}

bool Graph::validate() { return false; }

const std::vector<std::shared_ptr<GraphNode>>& Graph::getNodes() const { return nodes; }

const std::vector<std::shared_ptr<GraphPath>>& Graph::getPaths() const { return paths; }

bool operator==(const Graph& lhs, const Graph& rhs) {
    const std::vector<std::shared_ptr<GraphNode>> lhsNodes = lhs.getNodes();
    const std::vector<std::shared_ptr<GraphNode>> rhsNodes = rhs.getNodes();
    if (lhsNodes.size() != rhsNodes.size()) return false;
    for (const std::shared_ptr<GraphNode>& lhsNode : lhsNodes) {
        bool found = false;
        for (const std::shared_ptr<GraphNode>& rhsNode : rhsNodes) {
            if (*lhsNode == *rhsNode) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool operator!=(const Graph& lhs, const Graph& rhs) { return !(lhs == rhs); }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
