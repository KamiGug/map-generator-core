#ifndef MAP_GEN_LIB_TEST_HELPERS_MAKE_GRAPH_H
#define MAP_GEN_LIB_TEST_HELPERS_MAKE_GRAPH_H

#include <memory>

#include "entities/Biome.h"
#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Helpers::Test {

class MakeGraph {
   public:
    static std::shared_ptr<Entities::Graph> makeLinearGraph(size_t len = 3,
                                                            std::unique_ptr<Entities::GraphOptions> options = nullptr) {
        if (options == nullptr) {
            options = std::make_unique<Entities::GraphOptions>();
            options->autoValidate = false;
        }
        auto graph = std::make_shared<Entities::Graph>(std::move(options));
        if (len < 1) {
            return graph;
        }
        graph->addNode(std::make_shared<Entities::GraphNode>(
            std::make_shared<Entities::Biome>(std::make_unique<Entities::BiomeOptions>())));
        --len;
        for (size_t i = 0; i < len; ++i) {
            graph->addNode(graph->getNodes()[i],
                           std::make_shared<Entities::GraphNode>(
                               std::make_shared<Entities::Biome>(std::make_unique<Entities::BiomeOptions>())));
        }
        return graph;
    }
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Helpers::Test
#endif  // MAP_GEN_LIB_TEST_HELPERS_MAKE_GRAPH_H
