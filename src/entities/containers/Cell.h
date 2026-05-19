#ifndef MAP_GEN_LIB_ENTITIES_CELL_H
#define MAP_GEN_LIB_ENTITIES_CELL_H

#include <cstddef>
#include <memory>

#include "entities/Biome.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class Cell {
   public:
    inline Cell(size_t x, size_t y) : x(x), y(y) {}

    inline size_t getX() const { return this->x; }

    inline size_t getY() const { return this->y; }

    inline std::shared_ptr<Biome> getBiome() { return this->biome; }

   private:
    std::shared_ptr<Biome> biome = nullptr;
    const size_t x;
    const size_t y;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_CELL_H
