#include "RandomHandler.h"

#include <ctime>
#include <random>

namespace MAP_GEN_LIB_NAMESPACE {

RandomHandler* RandomHandler::get() {
    if (RandomHandler::instance != nullptr) return RandomHandler::instance;
    srand((unsigned)std::time(0));
    return RandomHandler::get((int)rand());
}
RandomHandler* RandomHandler::get(int seed) {
    if (RandomHandler::instance == nullptr) {
        RandomHandler::instance = new RandomHandler(seed);
    }
    return RandomHandler::instance;
}

RandomHandler::RandomHandler(int seed) {
    this->engine = new std::mt19937;
    setSeed(seed);
}

RandomHandler* RandomHandler::setSeed(int seed) {
    this->seed = seed;
    this->engine->seed(seed);
    return this;
}
int RandomHandler::getSeed() { return this->seed; };

RandomHandler* RandomHandler::instance = nullptr;

}  // namespace MAP_GEN_LIB_NAMESPACE
