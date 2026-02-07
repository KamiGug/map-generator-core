
#ifndef MAP_GEN_LIB_ENTITIES_SPACE_2D_INIT_OPTIONS_H
#define MAP_GEN_LIB_ENTITIES_SPACE_2D_INIT_OPTIONS_H

#include <cstddef>

namespace MAP_GEN_LIB_NAMESPACE::Entities {

struct Space2DInitOptions {
   public:
    std::size_t width = 100;
    std::size_t height = 100;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_SPACE_2D_INIT_OPTIONS_H
