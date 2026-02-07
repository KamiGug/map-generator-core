#ifndef MAP_GEN_LIB_CORE_WORLD_GENERATOR_H
#define MAP_GEN_LIB_CORE_WORLD_GENERATOR_H

#include <memory>

#include "Options.h"

namespace MAP_GEN_LIB_NAMESPACE {

class WorldGenerator {
   public:
    inline WorldGenerator() {
        auto _options = std::unique_ptr<Options>();
        WorldGenerator(std::move(_options));
    }

    inline WorldGenerator(Options*& options) {
        auto _options = std::unique_ptr<Options>(options);
        options = nullptr;
        WorldGenerator(std::move(_options));
    }

    WorldGenerator(std::unique_ptr<Options> options);

   private:
    std::unique_ptr<Options> options;
};
}  // namespace MAP_GEN_LIB_NAMESPACE
#endif  // MAP_GEN_LIB_CORE_WORLD_GENERATOR_H
