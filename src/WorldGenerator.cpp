#include "WorldGenerator.hpp"
#include "Options.hpp"
#include "RandomHandler.hpp"

namespace MAP_GEN_LIB_NAMESPACE {

WorldGenerator::WorldGenerator() { WorldGenerator(new Options()); }
WorldGenerator::WorldGenerator(Options *options) {
  this->randomHandler = new RandomHandler(options->getSeed());
  this->options = options;
  this->options->setGenerator(this);
}

RandomHandler *WorldGenerator::getRandomHandler() {
  return this->randomHandler;
}
} // namespace MAP_GEN_LIB_NAMESPACE
