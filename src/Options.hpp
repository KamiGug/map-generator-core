#ifndef MAP_GEN_LIB_CORE_OPTIONS_H
#define MAP_GEN_LIB_CORE_OPTIONS_H

namespace MAP_GEN_LIB_NAMESPACE {
class WorldGenerator;

class Options {
public:
  Options();

  void setSeed(int seed);
  int getSeed();

  void setGenerator(WorldGenerator *generator);
  WorldGenerator *getGenerator();

private:
  int seed;
  WorldGenerator *generator;
};
} // namespace MAP_GEN_LIB_NAMESPACE

#endif
