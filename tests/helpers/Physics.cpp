#include "helpers/Physics.h"

#include <gtest/gtest.h>

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;
namespace hlp = MAP_GEN_LIB_NAMESPACE::Helpers;

TEST(PhysicsHelper, Repulsion2D) {
    auto posA = ent::Vec<double, 2>({10, 10});
    auto posB = ent::Vec<double, 2>({13, 14});

    auto result = hlp::Physics::repulsion<ent::Vec<double, 2>>(25, posA, posB);
    ASSERT_EQ(result.length(), 1) << "Repulsion is 1";
    ASSERT_LT(result[0], 0) << "X is negative";
    ASSERT_LT(result[1], 0) << "Y is negative";
}

TEST(PhysicsHelper, RepulsionSamePosition) {
    auto pos = ent::Vec<double, 2>({10, 10});

    auto result = hlp::Physics::repulsion<ent::Vec<double, 2>>(1, pos, pos);
    ASSERT_EQ(result.length(), 0) << "Repulsion is 0";
    ASSERT_EQ(result[0], 0) << "X is zero";
    ASSERT_EQ(result[1], 0) << "Y is zero";
}

TEST(PhysicsHelper, Attraction2D) {
    auto posA = ent::Vec<double, 2>({10, 10});
    auto posB = ent::Vec<double, 2>({13, 14});

    auto result = hlp::Physics::attraction<ent::Vec<double, 2>>(0.2, posA, posB);
    ASSERT_EQ(result.length(), 1) << "Attracion is 1";
    ASSERT_GT(result[0], 0) << "X is positive";
    ASSERT_GT(result[1], 0) << "Y is positive";
}

TEST(PhysicsHelper, AttractionSamePosition) {
    auto pos = ent::Vec<double, 2>({10, 10});

    auto result = hlp::Physics::attraction<ent::Vec<double, 2>>(1, pos, pos);
    ASSERT_EQ(result.length(), 0) << "Attraction is 0";
    ASSERT_EQ(result[0], 0) << "X is zero";
    ASSERT_EQ(result[1], 0) << "Y is zero";
}
