#include "Graph.h"

#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPath.h"
#include "entities/graph/GraphPathOptions.h"
#include "exceptions/CyclicGraphException.h"
#include "exceptions/NotConnectedGraphException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {
bool Graph::addNode(std::shared_ptr<GraphNode> node, std::shared_ptr<GraphNode> parent,
                    std::unique_ptr<GraphPathOptions> pathOptions, std::optional<bool> autoValidate) {
    this->nodes.push_back(node);
    if (parent != nullptr) {
        this->addPath(parent, node, std::move(pathOptions));
    }
    return this->handleAutoValidation(autoValidate);
}

bool Graph::addPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end,
                    std::unique_ptr<GraphPathOptions> pathOptions, std::optional<bool> autoValidate) {
    if (pathOptions == nullptr) pathOptions = std::make_unique<GraphPathOptions>();
    std::shared_ptr<GraphPath> path = std::make_shared<GraphPath>(start, end, std::move(pathOptions));
    start->addPath(path);
    end->addPath(path);
    this->paths.push_back(path);
    return this->handleAutoValidation(autoValidate);
}

bool Graph::handleAutoValidation(std::optional<bool> validate) {
    bool shouldValidate = validate.value_or(this->autoValidate);
    if (shouldValidate) {
        try {
            this->_validate();
        } catch (Exceptions::CyclicGraphException e) {
            if (this->throwOnFailedAutoValidation)
                throw e;
            else
                return false;
        } catch (Exceptions::NotConnectedGraphException e) {
            if (this->throwOnFailedAutoValidation)
                throw e;
            else
                return false;
        }
        return true;
    } else {
        return true;
    }
}

bool Graph::validate() {
    try {
        _validate();
    } catch (Exceptions::CyclicGraphException e) {
        if (this->throwOnFailedAutoValidation)
            throw e;
        else
            return false;
    } catch (Exceptions::NotConnectedGraphException e) {
        if (this->throwOnFailedAutoValidation)
            throw e;
        else
            return false;
    }
    return true;
}

void Graph::_validate() {
    _validateConnected();
    // _validateAcyclic();
}

void Graph::_validateConnected() {
    if (nodes.empty()) {
        return;  // vacuously connected
    }

    // Build adjacency list (weak connectivity)
    std::unordered_map<const GraphNode*, std::vector<const GraphNode*>> adj;

    for (const auto& path : paths) {
        if (!path) continue;

        auto from = path->getFrom();
        auto to = path->getTo();

        if (!from || !to) continue;

        adj[from.get()].push_back(to.get());
        adj[to.get()].push_back(from.get());
    }

    // BFS from first node
    std::unordered_set<const GraphNode*> visited;
    std::queue<const GraphNode*> q;

    const GraphNode* start = nodes.front().get();
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        const GraphNode* current = q.front();
        q.pop();

        for (const GraphNode* neighbor : adj[current]) {
            if (!visited.contains(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    if (visited.size() != nodes.size()) {
        throw Exceptions::NotConnectedGraphException("Graph contains isolated subgraphs");
    }
}

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
