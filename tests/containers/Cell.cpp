#include "entities/containers/Cell.h"

#include <gtest/gtest.h>

#include <memory>

namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;

TEST(Cell, Construction) {
    std::shared_ptr<ent::Cell> cell = std::make_shared<ent::Cell>(0, 1);

    ASSERT_EQ(cell->getX(), 0) << "X is the first arg";
    ASSERT_EQ(cell->getY(), 1) << "Y is the second arg";
}
