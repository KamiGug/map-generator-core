#ifndef MAP_GEN_LIB_STEPS_GRAPH_PLACEMENT_PHYSICAL_BIOME_H
#define MAP_GEN_LIB_STEPS_GRAPH_PLACEMENT_PHYSICAL_BIOME_H

#include <memory>

#include "entities/Biome.h"
#include "entities/containers/Vec.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class PhysicalBiome {
   public:
    inline PhysicalBiome(double x, double y, std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Biome> biome) {
        this->position[0] = x;
        this->position[1] = y;
        this->biome = biome;
    }
    MAP_GEN_LIB_NAMESPACE::Entities::Vec<double, 2> position;
    std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Biome> biome;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_GRAPH_PLACEMENT_PHYSICAL_BIOME_H
