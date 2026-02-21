#include <gtest/gtest.h>

#include <memory>
#include <sstream>

#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/exporters/GMLExporter.h"
#include "helpers/StringHelper.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;
namespace hlp = MAP_GEN_LIB_NAMESPACE::Helpers;

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
    std::stringstream gmlOut;
    graph->addNode(node);
    ent::GMLExporter::write(*graph, gmlOut);
    std::string result = gmlOut.str();
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "graph"), 1) << "Graph is stated exactly once";
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "node"), graph->getNodes().size())
        << "Correct node count";
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "edge"), graph->getPaths().size())
        << "Correct path count";
    // auto node = std::make_unique<ent::GraphNode>();
}

TEST(GraphExport, ExportSinglePath) {
    auto graph = std::make_unique<ent::Graph>();

    auto node1 = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));
    auto node2 = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));
    std::stringstream gmlOut;
    graph->addNode(node1);
    graph->addNode(node1, node2);
    ent::GMLExporter::write(*graph, gmlOut);
    std::string result = gmlOut.str();
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "graph"), 1) << "Graph is stated exactly once";
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "node"), graph->getNodes().size())
        << "Correct node count";
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(result, "edge"), graph->getPaths().size())
        << "Correct path count";
    std::cout << result;
    FAIL();
}
