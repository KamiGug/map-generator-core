#include <gtest/gtest.h>

#include <memory>

#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/builders/GMLBuilder.h"
#include "entities/graph/builders/GenerateTreeBuilder.h"
#include "entities/graph/exporters/GMLExporter.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

// TEST(Graph, GMLTreeExportAndImport) {
//     MAP_GEN_LIB_NAMESPACE::RandomHandler::get(2000)->setSeed(2000);
//     MAP_GEN_LIB_NAMESPACE::Entities::GenerateTreeBuilder treeBuilder;
//     std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph> originalGraph =
//         std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph>(treeBuilder.build());

//     MAP_GEN_LIB_NAMESPACE::Entities::GMLExporter::write(originalGraph.get(), /* a stream here */);

//     MAP_GEN_LIB_NAMESPACE::Entities::GMLBuilder gmlBuilder =
//         MAP_GEN_LIB_NAMESPACE::Entities::GMLBuilder(graphGMLRepresentation);
//     std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph> otherGraph =
//         std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph>(gmlBuilder.build());
//     ASSERT_EQ(*originalGraph, *otherGraph);
// }

TEST(GraphExport, ExportSingleNode) {
    auto graph = std::make_unique<ent::Graph>();
    auto node = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));
    graph->addNode(node);
    ent::GMLExporter::write(*graph, std::cout);
    FAIL();
    // auto node = std::make_unique<ent::GraphNode>();
}

TEST(GraphExport, ExportSinglePath) {}
