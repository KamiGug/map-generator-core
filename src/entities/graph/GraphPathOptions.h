#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_PATH_OPTIONS_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_PATH_OPTIONS_H

#include <memory>
namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GraphPathOptions {
   public:
    bool bidirectional = false;

    inline bool equals(const GraphPathOptions& other) const {
        if (this->bidirectional != other.bidirectional) {
            return false;
        }

        return true;
    }

    GraphPathOptions* setBidirectional(bool val) {
        this->bidirectional = val;
        return this;
    }

    inline bool equals(const GraphPathOptions* other) const { return this->equals(*other); }

    inline bool equals(const std::shared_ptr<const GraphPathOptions>& other) const { return this->equals(*other); }
};

inline bool operator==(const GraphPathOptions& lhs, const GraphPathOptions& rhs) { return lhs.equals(rhs); }

inline bool operator!=(const GraphPathOptions& lhs, const GraphPathOptions& rhs) {
    // TODO: reimplement this
    return !(lhs == rhs);
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_PATH_OPTIONS_H
