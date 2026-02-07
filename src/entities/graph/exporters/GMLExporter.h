#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H

#include <string>
#include <vector>

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GMLExporter {
   public:
    static std::vector<std::string> transform(Graph* graph);
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H
