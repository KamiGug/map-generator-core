#include "entities/containers/Space2D.h"

#include <gtest/gtest.h>

#include <memory>

#include "entities/containers/Space2DOptions.h"
#include "exceptions/containers/OutOfSpaceBoundsException.h"

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;
namespace exc = MAP_GEN_LIB_NAMESPACE::Exceptions;

TEST(Space2D, CoordinatesAsExpected) {
    const size_t x = 5, y = 10;
    std::unique_ptr<ent::Space2D> space = std::make_unique<ent::Space2D>(std::make_unique<ent::Space2DOptions>(x, y));

    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < y; j++) {
            ASSERT_EQ(space->get(i, j)->getX(), i) << "Each Cell is passed correct X coordinate";
            ASSERT_EQ(space->get(i, j)->getY(), j) << "Each Cell is passed correct X coordinate";
        }
    }
}

TEST(Space2D, ThrowsOutOfBounds) {
    const size_t x = 5, y = 10;
    std::unique_ptr<ent::Space2D> space = std::make_unique<ent::Space2D>(std::make_unique<ent::Space2DOptions>(x, y));

    ASSERT_THROW(space->get(6, 4), exc::OutOfSpaceBoundsException) << "throws on out of bounds access";
    ASSERT_THROW(space->get(4, 12), exc::OutOfSpaceBoundsException) << "throws on out of bounds access";
}
