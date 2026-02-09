#include <gtest/gtest.h>

#include <memory>

#include "entities/Biome.h"
#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

TEST(Graph, SingleNode) {
    std::unique_ptr<ent::Graph> graph = std::unique_ptr<ent::Graph>(new ent::Graph());
    auto node = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));

    graph->addNode(node);
    ASSERT_EQ(graph->getNodes().size(), 1) << "there is 1 node in the graph";
    ASSERT_TRUE(graph->validate()) << "graph is valid";
}

TEST(Graph, AddNodeWithParent) {
    std::unique_ptr<ent::Graph> graph = std::unique_ptr<ent::Graph>(new ent::Graph());

    auto startNode = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));
    graph->addNode(startNode);

    auto pathOptions = std::unique_ptr<ent::GraphPathOptions>(new ent::GraphPathOptions());

    auto endNode = std::shared_ptr<ent::GraphNode>(new ent::GraphNode(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some other path"))));
    graph->addNode(endNode, graph->getNodes()[0], std::move(pathOptions));
    std::cout << graph->getNodes()[0]->getBiome()->getOptions().getPathToTileMap();

    ASSERT_EQ(graph->getNodes().size(), 2) << "correct count of nodes";
    ASSERT_EQ(graph->getPaths().size(), 1) << "correct count of paths";
    ASSERT_TRUE(graph->getNodes()[0]);
    ASSERT_TRUE(graph->getNodes()[0]->getPathsFrom()[0]);
    ASSERT_TRUE(graph->getNodes()[0]->getPathsFrom()[0]->isFrom(graph->getNodes()[0]))
        << "the first node is the same as the node path starts with";
    ASSERT_TRUE(graph->getNodes()[0]->getPathsFrom()[0]->isTo(graph->getNodes()[1]))
        << "the second node is the same as the node path ends in";
    ASSERT_TRUE(graph->validate()) << "graph is valid";
}

TEST(Graph, TwoSeparateNodes) {
    std::unique_ptr<ent::Graph> graph = std::unique_ptr<ent::Graph>(new ent::Graph(false));

    auto startNode = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(
        std::unique_ptr<ent::BiomeOptions>((new ent::BiomeOptions())->setPathToTileMap("some path"))));
    graph->addNode(startNode);
    auto endNode = std::shared_ptr<ent::GraphNode>(new ent::GraphNode(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some other path"))));
    graph->addNode(endNode);
    ASSERT_EQ(graph->getNodes().size(), 2) << "there are 2 nodes in the graph";
    ASSERT_EQ(graph->getPaths().size(), 0) << "there are no paths in the graph";
    ASSERT_FALSE(graph->validate()) << "graph is invalid";
}
