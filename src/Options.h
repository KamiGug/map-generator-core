#ifndef MAP_GEN_LIB_CORE_OPTIONS_H
#define MAP_GEN_LIB_CORE_OPTIONS_H

#include <optional>

#include "entities/graph/builders/AbstractGraphBuilder.h"
namespace MAP_GEN_LIB_NAMESPACE {
class WorldGenerator;

class Options {
   public:
    Options();

    Options* setSeed(int seed);
    int getSeed();

    Options* setGenerator(WorldGenerator* generator);
    WorldGenerator* getGenerator();

    Options* setGraphBuilder(Entities::AbstractGraphBuilder* graphBuilder);
    Entities::AbstractGraphBuilder* getGraphBuilder();

   private:
    std::optional<int> seed;
    WorldGenerator* generator = nullptr;
    Entities::AbstractGraphBuilder* graphBuilder = nullptr;
};
}  // namespace MAP_GEN_LIB_NAMESPACE

#endif  // MAP_GEN_LIB_CORE_OPTIONS_H
