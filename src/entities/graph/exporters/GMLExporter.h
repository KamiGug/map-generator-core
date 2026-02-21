#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H

#include <ostream>

#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GMLExporter {
   public:
    static void write(Graph& graph, std::ostream& out);

   private:
    static const uint8_t kSingleIndentLength = 2;
    static std::string indent(uint8_t level = 0) { return std::string(level * GMLExporter::kSingleIndentLength, ' '); }
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_EXPORTERS_GML_H
