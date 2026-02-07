#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_PATH_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_PATH_H

#include <memory>

#include "entities/graph/GraphPathOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphNode;

class GraphPath {
   public:
    inline GraphPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end)
        : GraphPath(start, end, std::make_unique<GraphPathOptions>()) {}

    inline GraphPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end, GraphPathOptions*& options)
        : GraphPath(start, end, std::unique_ptr<GraphPathOptions>(options)) {
        options = nullptr;
    }

    GraphPath(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> end,
              std::unique_ptr<GraphPathOptions> options);

    // const std::vector<GraphNode *> getFrom() const;

    // const std::vector<GraphNode *> getTo() const;

    inline bool isFrom(const std::shared_ptr<GraphNode>& node) const { return this->isFrom(node.get()); }
    bool isFrom(const GraphNode* node) const;

    inline bool isTo(const std::shared_ptr<GraphNode>& node) const { return this->isTo(node.get()); }
    bool isTo(const GraphNode* node) const;

    inline bool isBidirectional() const { return this->options->bidirectional; };

    inline bool equals(std::shared_ptr<GraphPath> other) const {
        if (other != nullptr) {
            return this->equals(*(other));
        }
        return false;
    }

    bool equals(const GraphPath& other) const;

    inline bool equals(GraphPath* other) const {
        if (other != nullptr) {
            return this->equals(*(other));
        }
        return false;
    }

   private:
    std::unique_ptr<GraphPathOptions> options;
    std::weak_ptr<GraphNode> from;
    std::weak_ptr<GraphNode> to;
};

bool operator==(const GraphPath& lhs, const GraphPath& rhs);
bool operator!=(const GraphPath& lhs, const GraphPath& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_PATH_H
