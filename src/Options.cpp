#include "Options.h"

#include <cstdlib>

#include "RandomHandler.h"
#include "WorldGenerator.h"

namespace MAP_GEN_LIB_NAMESPACE {

Options::Options() { this->setSeed(std::rand()); }

Options* Options::setSeed(int seed) {
    this->seed = seed;
    RandomHandler::get()->setSeed(seed);
    return this;
}
int Options::getSeed() {
    if (this->seed.has_value()) {
        return this->seed.value();
    }
    this->seed = RandomHandler::get()->getSeed();
    return this->seed.value();
}

Options* Options::setGenerator(WorldGenerator* generator) {
    this->generator = generator;
    return this;
}
WorldGenerator* Options::getGenerator() { return this->generator; }
Options* Options::setGraphBuilder(Entities::AbstractGraphBuilder* graphBuilder) {
    this->graphBuilder = graphBuilder;
    return this;
}
Entities::AbstractGraphBuilder* Options::getGraphBuilder() { return this->graphBuilder; }

}  // namespace MAP_GEN_LIB_NAMESPACE
