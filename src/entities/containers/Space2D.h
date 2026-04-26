#ifndef MAP_GEN_LIB_ENTITIES_SPACE_2D_H
#define MAP_GEN_LIB_ENTITIES_SPACE_2D_H

#include <cstddef>
#include <memory>

#include "Cell.h"
#include "Space2DOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class Space2D {
   public:
    Space2D(std::unique_ptr<Space2DOptions> options = nullptr);
    ~Space2D();

    std::shared_ptr<Cell> get(size_t x, size_t y);

   private:
    std::shared_ptr<Cell>** space;
    std::unique_ptr<Space2DOptions> options;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_SPACE_2D_H
