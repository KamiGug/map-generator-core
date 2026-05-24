#include <gtest/gtest.h>

#include <iostream>
#include <memory>

#include "exceptions/NotImplementedException.h"
#include "helpers/test/MakeGraph.h"
#include "steps/graphMapping/ForceDirectedLayout/ForceDirectedLayoutOptions.h"
#include "steps/graphMapping/ForceDirectedLayout/ForceDirectedLayoutStep.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;
namespace exc = MAP_GEN_LIB_NAMESPACE::Exceptions;
namespace stp = MAP_GEN_LIB_NAMESPACE::Steps;
namespace hlp = MAP_GEN_LIB_NAMESPACE::Helpers;
namespace tst = hlp::Test;

TEST(ForceDirectedLayoutStep, Repulsion) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0;
    options->repulsionConstant = 10;
    options->height = 100;
    options->width = 100;
    auto graph = tst::MakeGraph::makeLinearGraph(2);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    step->init();
    auto startingDistance = (step->physicalBiomes[0]->position - step->physicalBiomes[1]->position).length();
    step->iterate();
    auto afterIterationDistance = (step->physicalBiomes[0]->position - step->physicalBiomes[1]->position).length();

    ASSERT_GT(afterIterationDistance, startingDistance) << "Distance increased";
}

TEST(ForceDirectedLayoutStep, Attraction) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 1;
    options->repulsionConstant = 0;
    options->height = 100;
    options->width = 100;
    auto graph = tst::MakeGraph::makeLinearGraph(2);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    step->init();
    auto startingDistance = (step->physicalBiomes[0]->position - step->physicalBiomes[1]->position).length();
    step->iterate();
    auto afterIterationDistance = (step->physicalBiomes[0]->position - step->physicalBiomes[1]->position).length();

    ASSERT_LT(afterIterationDistance, startingDistance) << "Distance increased";
}

TEST(ForceDirectedLayoutStep, EntireTransform) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0.3;
    options->repulsionConstant = 2;
    options->height = 100;
    options->width = 100;
    uint8_t nodeCount = 3;
    auto graph = tst::MakeGraph::makeLinearGraph(nodeCount);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    auto result = step->transform();
    for (uint8_t i = 0; i < nodeCount; ++i) {
        ASSERT_TRUE(result[i]->position[0] >= 0 &&
                    result[i]->position[0] < options->width - options->marginLeft - options->marginRight &&
                    result[i]->position[1] >= 0 &&
                    result[i]->position[1] < options->height - options->marginBottom - options->marginTop)
            << "Coordinates within limits failed on node" << i << " position: " << result[i]->position[0] << " x "
            << result[i]->position[1];
    }
}

TEST(ForceDirectedLayoutStep, LargeScaleEntireTransform) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0.3;
    options->repulsionConstant = 2;
    options->height = 10000;
    options->width = 10000;
    uint8_t nodeCount = 100;
    auto graph = tst::MakeGraph::makeLinearGraph(nodeCount);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    auto result = step->transform();
    for (uint8_t i = 0; i < nodeCount; ++i) {
        ASSERT_TRUE(result[i]->position[0] >= 0 &&
                    result[i]->position[0] < options->width - options->marginLeft - options->marginRight &&
                    result[i]->position[1] >= 0 &&
                    result[i]->position[1] < options->height - options->marginBottom - options->marginTop)
            << "Coordinates within limits failed on node" << i << " position: " << result[i]->position[0] << " x "
            << result[i]->position[1];
    }
}

TEST(ForceDirectedLayoutStep, StopBorderStrategy) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0.3;
    options->repulsionConstant = 2;
    options->height = 100;
    options->width = 100;
    options->borderStrategy = stp::ForceDirectedLayoutOptions::BorderStrategy::STOP;
    uint8_t nodeCount = 3;
    auto graph = tst::MakeGraph::makeLinearGraph(nodeCount);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    step->init();
    auto position = ent::Vec<double, 2>({-10, -10});
    EXPECT_THROW(step->handleBorderStrategies(position), exc::NotImplementedException);
}

TEST(ForceDirectedLayoutStep, SlideBorderStrategy) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0.3;
    options->repulsionConstant = 2;
    options->height = 100;
    options->width = 100;
    options->borderStrategy = stp::ForceDirectedLayoutOptions::BorderStrategy::SLIDE;
    uint8_t nodeCount = 3;
    auto graph = tst::MakeGraph::makeLinearGraph(nodeCount);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    step->init();
    auto position = ent::Vec<double, 2>({-10, -10});
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 0);
    EXPECT_EQ(position[1], 0);

    position[0] = -10;
    position[1] = 50;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 0);
    EXPECT_EQ(position[1], 50);

    position[0] = 50;
    position[1] = 50;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 50);
    EXPECT_EQ(position[1], 50);

    position[0] = 150;
    position[1] = 30;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 99);
    EXPECT_EQ(position[1], 30);

    position[0] = 30;
    position[1] = 130;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 30);
    EXPECT_EQ(position[1], 99);

    position[0] = 30;
    position[1] = -12;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 30);
    EXPECT_EQ(position[1], 0);

    position[0] = 321;
    position[1] = 123;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 99);
    EXPECT_EQ(position[1], 99);
}

TEST(ForceDirectedLayoutStep, BounceBorderStrategy) {
    auto options = std::make_shared<stp::ForceDirectedLayoutOptions>();
    options->attractionConstant = 0.3;
    options->repulsionConstant = 2;
    options->height = 101;
    options->width = 101;
    options->borderStrategy = stp::ForceDirectedLayoutOptions::BorderStrategy::BOUNCE;
    uint8_t nodeCount = 3;
    auto graph = tst::MakeGraph::makeLinearGraph(nodeCount);
    auto step = std::make_shared<stp::ForceDirectedLayoutStep>(graph, options);
    step->init();
    auto position = ent::Vec<double, 2>({-10, -10});
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 10);
    EXPECT_EQ(position[1], 10);

    position[0] = -10;
    position[1] = 50;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 10);
    EXPECT_EQ(position[1], 50);

    position[0] = 50;
    position[1] = 50;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 50);
    EXPECT_EQ(position[1], 50);

    position[0] = 150;
    position[1] = 30;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 50);
    EXPECT_EQ(position[1], 30);

    position[0] = 30;
    position[1] = 130;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 30);
    EXPECT_EQ(position[1], 70);

    position[0] = 30;
    position[1] = -12;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 30);
    EXPECT_EQ(position[1], 12);

    position[0] = 120;
    position[1] = 123;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 80);
    EXPECT_EQ(position[1], 77);

    position[0] = 230;
    position[1] = -120;
    step->handleBorderStrategies(position);
    EXPECT_EQ(position[0], 30);
    EXPECT_EQ(position[1], 80);
}
