#ifndef MAP_GEN_LIB_CORE_WORLD_GENERATOR_H
#define MAP_GEN_LIB_CORE_WORLD_GENERATOR_H

#include "Options.hpp"
#include "RandomHandler.hpp"

namespace MAP_GEN_LIB_NAMESPACE {

class WorldGenerator {
public:
  WorldGenerator();

  WorldGenerator(Options *options);

  RandomHandler *getRandomHandler();

private:
  RandomHandler *randomHandler;
  Options *options;
};
} // namespace MAP_GEN_LIB_NAMESPACE
#endif
