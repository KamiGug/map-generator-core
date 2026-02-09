#include "Biome.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

bool operator==(const Biome& lhs, const Biome& rhs) {
    if (lhs.getOptions() != rhs.getOptions()) return false;
    return true;
}

uint16_t Biome::nextId = 0;

bool operator!=(const Biome& lhs, const Biome& rhs) { return !(lhs == rhs); }
}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
