#ifndef MAP_GEN_LIB_ENTITIES_SPACE_2D_H
#define MAP_GEN_LIB_ENTITIES_SPACE_2D_H

#include <cstddef>
#include <cstdint>

#include "Space2DInitOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class Space2D {
   public:
    Space2D(Space2DInitOptions* options = nullptr);
    ~Space2D();

    uint64_t get(size_t x, size_t y);

    void set(size_t x, size_t y, uint64_t value);

   private:
    uint64_t** space;
    size_t width;
    size_t height;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_SPACE_2D_H
