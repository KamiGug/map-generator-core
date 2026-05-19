#ifndef MAP_GEN_LIB_CORE_WORLD_GENERATOR_H
#define MAP_GEN_LIB_CORE_WORLD_GENERATOR_H

#include <memory>

#include "Options.h"

namespace MAP_GEN_LIB_NAMESPACE {

class WorldGenerator {
   public:
    inline WorldGenerator() : WorldGenerator(std::make_unique<Options>()) {}

    WorldGenerator(std::unique_ptr<Options> options);

   private:
    std::unique_ptr<Options> options;
};
}  // namespace MAP_GEN_LIB_NAMESPACE
#endif  // MAP_GEN_LIB_CORE_WORLD_GENERATOR_H
