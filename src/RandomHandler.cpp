#include "RandomHandler.hpp"
// #include <cstdlib>
// #include <random>

namespace MAP_GEN_LIB_NAMESPACE {
RandomHandler::RandomHandler(int seed) { setSeed(seed); }

void RandomHandler::setSeed(int seed) {
  this->seed = seed;
  // srand(this->Seed);
}
int RandomHandler::getSeed() { return this->seed; };

int RandomHandler::getInt(int min, int max) { return 0; }

double RandomHandler::getDouble(double min, double max) { return 0.0; }
float RandomHandler::getFloat(float min, double max) { return 0.0f; }

} // namespace MAP_GEN_LIB_NAMESPACE
