#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_OPTIONS_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_OPTIONS_H

namespace MAP_GEN_LIB_NAMESPACE::Entities {
class GraphOptions {
   public:
    bool autoValidate = true;
    bool throwOnFailedExplicitValidation = false;
    bool throwOnFailedAutoValidation = false;
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_OPTIONS_H
