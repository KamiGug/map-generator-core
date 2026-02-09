#ifndef MAP_GEN_LIB_ENTITIES_BIOME_H
#define MAP_GEN_LIB_ENTITIES_BIOME_H

#include <cstdint>
#include <memory>

#include "entities/BiomeOptions.h"
#include "exceptions/InvalidBiomeOptionsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class Biome {
   public:
    inline Biome(BiomeOptions*& options) : Biome(std::unique_ptr<BiomeOptions>(options)) { options = nullptr; }
    inline Biome(BiomeOptions* options) : Biome(std::unique_ptr<BiomeOptions>(options)) {}

    inline Biome(std::unique_ptr<BiomeOptions> options) {
        if (options == nullptr) throw Exceptions::InvalidBiomeOptionsException("Missing options exception");
        this->id = Biome::getNextId();
        this->options = std::move(options);
    }

    inline const BiomeOptions& getOptions() const { return *(this->options); }

    inline uint16_t getId() const { return id; }

   private:
    static uint16_t nextId;
    inline static uint16_t getNextId() { return Biome::nextId++; }
    uint16_t id;
    std::unique_ptr<BiomeOptions> options;

    // static std::unordered_map<uint16_t, std::weak_ptr<Biome>> BiomeMap;
};

bool operator==(const Biome& lhs, const Biome& rhs);

bool operator!=(const Biome& lhs, const Biome& rhs);
}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif  // MAP_GEN_LIB_ENTITIES_BIOME_H
