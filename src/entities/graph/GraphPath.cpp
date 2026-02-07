#include "entities/graph/GraphPath.h"

#include <memory>

#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"
#include "exceptions/InvalidGraphNodeException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

GraphPath::GraphPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end,
                     std::unique_ptr<GraphPathOptions> options) {
    if (start == nullptr) {
        throw Exceptions::InvalidGraphNodeException("Invalid start node");
    }
    if (end == nullptr) {
        throw Exceptions::InvalidGraphNodeException("Invalid end node");
    }
    this->from = std::weak_ptr<GraphNode>(start);
    this->to = std::weak_ptr<GraphNode>(end);
    if (options != nullptr) {
        this->options = std::move(options);
    } else {
        this->options = std::unique_ptr<GraphPathOptions>(new GraphPathOptions());
    }
}

// const std::vector<GraphNode *> GraphPath::getFrom() const {
//   if (this->options->bidirectional) {
//     return {this->from, this->to};
//   }
//   return {this->from};
// }

// const std::vector<GraphNode *> GraphPath::getTo() const {
//   if (this->options->bidirectional) {
//     return {this->to, this->from};
//   }
//   return {this->to};
// }

bool GraphPath::isFrom(const GraphNode* node) const {
    return node && (this->from.lock().get() == node || (this->options->bidirectional && this->to.lock().get() == node));
}

bool GraphPath::isTo(const GraphNode* node) const {
    return node && (this->to.lock().get() == node || (this->options->bidirectional && this->from.lock().get() == node));
}

bool GraphPath::equals(const GraphPath& other) const {
    if (!this->options->equals(*(other.options))) return false;
    return true;
}

bool operator==(const GraphPath& lhs, const GraphPath& rhs) { return lhs.equals(rhs); }

bool operator!=(const GraphPath& lhs, const GraphPath& rhs) { return !lhs.equals(rhs); }
}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
