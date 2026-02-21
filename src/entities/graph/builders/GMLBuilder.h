#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H

#include "AbstractGraphBuilder.h"
#include "entities/graph/Graph.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GMLBuilder : public AbstractGraphBuilder {
   public:
    inline GMLBuilder(std::istream& input) { this->input = input; }
    std::unique_ptr<Graph> build() override;

   private:
    std::istream input;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_BUILDER_H
