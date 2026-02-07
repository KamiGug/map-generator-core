#ifndef MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H
#define MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H

#include <string>

#include "exceptions/InvalidBiomeOptionsException.h"
namespace MAP_GEN_LIB_NAMESPACE::Entities {

class BiomeOptions {
   public:
    inline BiomeOptions() {}

    inline const std::string getPathToTileMap() const {
        if (this->pathToTileMap == "") throw Exceptions::InvalidBiomeOptionsException("Missing pathToTileMap");
        return this->pathToTileMap;
    }

    inline BiomeOptions* setPathToTileMap(std::string path) {
        this->pathToTileMap = path;
        return this;
    }

   private:
    std::string pathToTileMap;
};

bool operator==(const BiomeOptions& lhs, const BiomeOptions& rhs);

bool operator!=(const BiomeOptions& lhs, const BiomeOptions& rhs);

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_BIOME_OPTIONS_H
