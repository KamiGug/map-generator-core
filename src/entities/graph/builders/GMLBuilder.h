#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H

#include <string>
#include <vector>

#include "AbstractGraphBuilder.h"
#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GMLBuilder : public AbstractGraphBuilder {
   public:
    GMLBuilder(std::vector<std::string>& graphDefinition);
    Graph* build() override;

   private:
    std::vector<std::string> graphDefinition;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H
