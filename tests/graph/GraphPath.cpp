#include "entities/graph/GraphPath.h"

#include <gtest/gtest.h>

#include <memory>

#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphPathOptions.h"
#include "exceptions/InvalidGraphNodeException.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

TEST(GraphPath, MissingStartNode) {
    std::unique_ptr<ent::BiomeOptions> biomeOptions = std::make_unique<ent::BiomeOptions>();
    biomeOptions->setPathToTileMap("some path");
    auto graphNode = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(std::move(biomeOptions)));

    ent::GraphPath* graphPath = nullptr;
    ASSERT_THROW(graphPath = new ent::GraphPath(graphNode, nullptr),
                 MAP_GEN_LIB::Exceptions::InvalidGraphNodeException);
    delete graphPath;
}

TEST(GraphPath, MissingEndNode) {
    auto biomeOptions = std::make_unique<ent::BiomeOptions>();
    biomeOptions->setPathToTileMap("some path");
    auto graphNode = std::make_shared<ent::GraphNode>(std::make_shared<ent::Biome>(std::move(biomeOptions)));

    ent::GraphPath* graphPath = nullptr;
    ASSERT_THROW(graphPath = new ent::GraphPath(nullptr, graphNode),
                 MAP_GEN_LIB::Exceptions::InvalidGraphNodeException);
    delete graphPath;
}

TEST(GraphPath, SinglePathFromToFilled) {
    auto startNode = std::make_shared<ent::GraphNode>(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some path")));

    auto endNode = std::make_shared<ent::GraphNode>(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some other path")));
    auto graphPath = std::unique_ptr<ent::GraphPath>(new ent::GraphPath(startNode, endNode));

    EXPECT_TRUE(graphPath->isFrom(startNode));
    EXPECT_TRUE(graphPath->isTo(endNode));
}

TEST(GraphPath, SinglePathFromToFilledBidirectional) {
    auto startNode = std::make_shared<ent::GraphNode>(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some path")));

    auto endNode = std::make_shared<ent::GraphNode>(
        std::make_shared<ent::Biome>((new ent::BiomeOptions())->setPathToTileMap("some other path")));

    ent::GraphPathOptions* pathOptions = new ent::GraphPathOptions();
    pathOptions->bidirectional = true;

    auto graphPath = std::make_unique<ent::GraphPath>(startNode, endNode, pathOptions);

    EXPECT_TRUE(graphPath->isFrom(startNode));
    EXPECT_TRUE(graphPath->isFrom(endNode));
    EXPECT_TRUE(graphPath->isTo(endNode));
    EXPECT_TRUE(graphPath->isTo(startNode));
}
