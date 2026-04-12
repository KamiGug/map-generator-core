#include <gtest/gtest.h>

#include <memory>

#include "entities/Biome.h"
#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"

// TODO: actually make this a round about

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

class GraphProgrammaticRoundAbout : public ::testing::Test {
   protected:
    std::shared_ptr<ent::GraphNode> makeNode(const std::string& path) {
        return std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
            std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap(path))));
    }
};

TEST_F(GraphProgrammaticRoundAbout, SingleNode) {
    auto graph = std::make_unique<ent::Graph>();

    auto node = makeNode("forest.map");
    graph->addNode(node);

    ASSERT_EQ(graph->getNodes().size(), 1);
    ASSERT_EQ(graph->getPaths().size(), 0);
    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphProgrammaticRoundAbout, TwoNodesDisconnected) {
    auto graph = std::make_unique<ent::Graph>();

    auto node1 = makeNode("forest.map");
    auto node2 = makeNode("desert.map");

    graph->addNode(node1);
    graph->addNode(node2);

    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 0);
    ASSERT_FALSE(graph->validate());  // disconnected
}

TEST_F(GraphProgrammaticRoundAbout, TwoNodesWithPath) {
    auto graph = std::make_unique<ent::Graph>();

    auto node1 = makeNode("forest.map");
    auto node2 = makeNode("desert.map");

    graph->addNode(node1);

    auto pathOptions = std::make_unique<ent::GraphPathOptions>();
    graph->addNode(node2, node1, std::move(pathOptions));

    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 1);

    ASSERT_TRUE(graph->getPaths()[0]->isFrom(node1));
    ASSERT_TRUE(graph->getPaths()[0]->isTo(node2));

    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphProgrammaticRoundAbout, ThreeNodesLinearChain) {
    auto graph = std::make_unique<ent::Graph>();

    auto node1 = makeNode("forest.map");
    auto node2 = makeNode("desert.map");
    auto node3 = makeNode("mountain.map");

    graph->addNode(node1);

    graph->addNode(node2, node1, std::make_unique<ent::GraphPathOptions>());
    graph->addNode(node3, node2, std::make_unique<ent::GraphPathOptions>());

    ASSERT_EQ(graph->getNodes().size(), 3);
    ASSERT_EQ(graph->getPaths().size(), 2);
    ASSERT_TRUE(graph->validate());
}

TEST_F(GraphProgrammaticRoundAbout, ExplicitlyDisconnectedGraphMode) {
    std::unique_ptr<ent::GraphOptions> options = std::make_unique<ent::GraphOptions>();
    options->autoValidate = false;

    auto graph = std::make_unique<ent::Graph>(std::move(options));

    auto node1 = makeNode("forest.map");
    auto node2 = makeNode("desert.map");

    graph->addNode(node1);
    graph->addNode(node2);

    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 0);

    // Should be invalid if connectivity required
    ASSERT_FALSE(graph->validate());
}
