#include <gtest/gtest.h>

#include <memory>
#include <sstream>

#include "entities/graph/Graph.h"
#include "entities/graph/GraphOptions.h"
#include "entities/graph/builders/TokenizerBuilder.h"
#include "entities/graph/builders/tokens/GMLTokenizer.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

class GraphGMLRoundAbout : public ::testing::Test {
   protected:
    std::unique_ptr<ent::Graph> buildGraphFromGML(const std::string& gmlText,
                                                  std::unique_ptr<ent::GraphOptions> options = nullptr) {
        auto input = std::make_shared<std::istringstream>(gmlText);
        ent::TokenizerBuilder<ent::GMLTokenizer> builder(input);
        return builder.build(std::move(options));
    }
};

TEST_F(GraphGMLRoundAbout, SingleNode) {
    std::string gml = R"(
        node [ id 1 biomeId 10 ]
        biome [ id 10 pathToTileMap "forest.map" ]
    )";

    auto graph = buildGraphFromGML(gml);
    ASSERT_EQ(graph->getNodes().size(), 1);
    ASSERT_EQ(graph->getPaths().size(), 0);
    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphGMLRoundAbout, TwoNodes) {
    std::string gml = R"(
        node [ id 1 biomeId 10 ]
        node [ id 2 biomeId 20 ]
        biome [ id 10 pathToTileMap "forest.map" ]
        biome [ id 20 pathToTileMap "desert.map" ]
    )";

    auto options = std::make_unique<ent::GraphOptions>();
    options->autoValidate = false;
    options->throwOnFailedExplicitValidation = false;
    auto graph = buildGraphFromGML(gml, std::move(options));
    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 0);
    ASSERT_FALSE(graph->validate());  // no connecting paths
}

TEST_F(GraphGMLRoundAbout, TwoNodesWithPath) {
    std::string gml = R"(
        node [ id 1 biomeId 10 ]
        node [ id 2 biomeId 20 ]
        edge [ source 1 target 2 bidirectional 1 ]
        biome [ id 10 pathToTileMap "forest.map" ]
        biome [ id 20 pathToTileMap "desert.map" ]
    )";

    auto graph = buildGraphFromGML(gml);
    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 1);
    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphGMLRoundAbout, StartingWithGMLKeyword) {
    std::string gml = R"(
        graph [
            node [ id 1 biomeId 10 ]
            biome [ id 10 pathToTileMap "forest.map" ]
        ]
    )";

    auto graph = buildGraphFromGML(gml);
    ASSERT_EQ(graph->getNodes().size(), 1);
    ASSERT_EQ(graph->getPaths().size(), 0);
    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphGMLRoundAbout, StartingWithGraphKeyword) {
    std::string gml = R"(
        graph [
            node [ id 1 biomeId 10 ]
            node [ id 2 biomeId 20 ]
            edge [ source 1 target 2 bidirectional 1 ]
            biome [ id 10 pathToTileMap "forest.map" ]
            biome [ id 20 pathToTileMap "desert.map" ]
        ]
    )";

    auto graph = buildGraphFromGML(gml);
    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 1);
    ASSERT_TRUE(graph->validate());
}
