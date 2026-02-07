#include "BiomeOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

bool operator==(const BiomeOptions& lhs, const BiomeOptions& rhs) {
    if (lhs.getPathToTileMap() != rhs.getPathToTileMap()) return false;

    return true;
}

bool operator!=(const BiomeOptions& lhs, const BiomeOptions& rhs) { return !(lhs == rhs); }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
