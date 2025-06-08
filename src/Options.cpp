#include "Options.hpp"
#include "WorldGenerator.hpp"
#include <string>

using std::string;

namespace MAP_GEN_LIB_NAMESPACE {

Options::Options() { this->setSeed(std::rand()); }

void Options::setSeed(int seed) {
  this->seed = seed;
  if (this->getGenerator() != nullptr) {
    this->getGenerator()->getRandomHandler()->setSeed(seed);
  }
}
int Options::getSeed() { return this->seed; }

void Options::setGenerator(WorldGenerator *generator) {
  this->generator = generator;
}
WorldGenerator *Options::getGenerator() { return this->generator; }
} // namespace MAP_GEN_LIB_NAMESPACE
