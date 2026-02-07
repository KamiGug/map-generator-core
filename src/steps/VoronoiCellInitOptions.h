#ifndef MAP_GEN_LIB_STEPS_VORONOI_CELL_INIT_OPTIONS_H
#define MAP_GEN_LIB_STEPS_VORONOI_CELL_INIT_OPTIONS_H

#include <cstdint>

namespace MAP_GEN_LIB_NAMESPACE::Steps {

struct VoronoiCellInitOptions {
    std::uint16_t count = 25;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_VORONOI_CELL_INIT_OPTIONS_H
