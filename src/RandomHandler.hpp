#ifndef MAP_GEN_LIB_CORE_RANDOM_HANDLER_H
#define MAP_GEN_LIB_CORE_RANDOM_HANDLER_H

namespace MAP_GEN_LIB_NAMESPACE {
class RandomHandler {
public:
  RandomHandler(int seed);

  void setSeed(int seed);
  int getSeed();

  int getInt(int min = 0, int max = 0);
  double getDouble(double min = 0, double max = 0);
  float getFloat(float min = 0, double max = 0);

private:
  int seed;
};
} // namespace MAP_GEN_LIB_NAMESPACE
#endif
