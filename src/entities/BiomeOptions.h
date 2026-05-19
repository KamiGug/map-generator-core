#ifndef MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H
#define MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H

#include <cstdint>
#include <optional>
#include <string>

#include "exceptions/graph/InvalidBiomeOptionsException.h"
namespace MAP_GEN_LIB_NAMESPACE::Entities {

class BiomeOptions {
   public:
    inline BiomeOptions() {}

    inline const std::string getPathToTileMap() const {
        if (this->pathToTileMap == "") throw Exceptions::InvalidBiomeOptionsException("Missing pathToTileMap");
        return this->pathToTileMap;
    }

    BiomeOptions* setPathToTileMap(std::string path) {
        this->pathToTileMap = path;
        return this;
    }

    BiomeOptions* setId(uint16_t id);

    uint16_t getId();

   private:
    static uint16_t nextId;
    inline static uint16_t getNextId() { return BiomeOptions::nextId++; }
    std::string pathToTileMap;
    std::optional<uint16_t> id = std::nullopt;
};

bool operator==(const BiomeOptions& lhs, const BiomeOptions& rhs);

bool operator!=(const BiomeOptions& lhs, const BiomeOptions& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H
