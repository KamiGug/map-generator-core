#include <gtest/gtest.h>

#include <memory>
#include <sstream>

#include "entities/graph/builders/TokenizerBuilder.h"
#include "entities/graph/builders/tokens/GMLTokenizer.h"

using namespace MAP_GEN_LIB_NAMESPACE::Entities;

// TODO: Improve this test suite

TEST(TokenizerBuilder, SimpleGraph) {
    std::shared_ptr<std::istringstream> input = std::make_shared<std::istringstream>(R"(
        node [ id 1 biomeId 10 ]
        node [ id 2 biomeId 20 ]
        edge [ source 1 target 2 bidirectional 1 ]
        biome [ id 10 pathToTileMap "forest.map" ]
        biome [ id 20 pathToTileMap "desert.map" ]
    )");

    TokenizerBuilder<GMLTokenizer> builder(input);
    auto graph = builder.build();

    ASSERT_EQ(graph->getNodes().size(), 2);
    ASSERT_EQ(graph->getPaths().size(), 1);

    auto nodes = graph->getNodes();
    EXPECT_EQ(nodes.size(), 2) << "Exactly 2 nodes";
    // EXPECT_EQ(nodes[0]->getId(), 1);
    // EXPECT_EQ(nodes[1]->getId(), 2);

    auto paths = graph->getPaths();
    EXPECT_EQ(paths.size(), 1) << "Exactly 1 path";
    EXPECT_EQ(paths[0]->getFrom(), nodes[0]) << "Path starts in the first node";
    EXPECT_EQ(paths[0]->getTo(), nodes[1]) << "Path ends in the second node";
    // EXPECT_EQ(paths[0]->getFrom()->getId(), 1);
    // EXPECT_EQ(paths[0]->getTo()->getId(), 2);
    EXPECT_TRUE(paths[0]->isBidirectional()) << "Path is bidirectional";
}
