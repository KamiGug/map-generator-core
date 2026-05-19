#include "BiomeOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

BiomeOptions* BiomeOptions::setId(uint16_t id) {
    if (!this->id.has_value()) {
        this->id = id;
    }
    // TODO: consider throwing when setting the id if it was already set
    return this;
}

uint16_t BiomeOptions::getId() {
    if (!this->id.has_value()) {
        this->setId(BiomeOptions::getNextId());
    }
    return this->id.value();
}
bool operator==(const BiomeOptions& lhs, const BiomeOptions& rhs) {
    if (lhs.getPathToTileMap() != rhs.getPathToTileMap()) return false;

    return true;
}

uint16_t BiomeOptions::nextId = 0;
bool operator!=(const BiomeOptions& lhs, const BiomeOptions& rhs) { return !(lhs == rhs); }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
