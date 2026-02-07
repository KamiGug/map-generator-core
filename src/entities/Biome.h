#ifndef MAP_GEN_LIB_ENTITIES_BIOME_H
#define MAP_GEN_LIB_ENTITIES_BIOME_H

#include "entities/BiomeOptions.h"
#include "exceptions/InvalidBiomeOptionsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class Biome {
   public:
    inline Biome(BiomeOptions* options) {
        if (options == nullptr) throw Exceptions::InvalidBiomeOptionsException("Missing options exception");
        this->options = options;
    }

    inline ~Biome() {
        if (options != nullptr) delete options;
    }

    inline BiomeOptions* getOptions() const { return this->options; }

   private:
    BiomeOptions* options = nullptr;
};

bool operator==(const Biome& lhs, const Biome& rhs);

bool operator!=(const Biome& lhs, const Biome& rhs);
}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_BIOME_H
