#ifndef MAP_GEN_LIB_CORE_RANDOM_HANDLER_H
#define MAP_GEN_LIB_CORE_RANDOM_HANDLER_H

#include <concepts>
#include <random>

namespace MAP_GEN_LIB_NAMESPACE {
class RandomHandler {
   public:
    static RandomHandler* get();
    static RandomHandler* get(int seed);

    RandomHandler* setSeed(int seed);
    int getSeed() const;

    template <std::integral T>
    T getRand(T min = 0, T max = 0) const {
        if (min == max) return min;
        if (min > max) swap(min, max);
        std::uniform_int_distribution<T> dist(min, max);
        return dist(this->engine);
    }

    template <std::floating_point T>
    T getRand(T min = 0, T max = 0) const {
        if (min == max) return min;
        if (min > max) swap(min, max);
        std::uniform_real_distribution<T> dist(min, max);
        return dist(this->engine);
    }

    // template <Entities::ArithmeticCoord T, size_t N>
    // Entities::Vec<T, N> getRand(T len) {
    //   return new Entities::Vec<T, N>();
    // }

   private:
    static RandomHandler* instance;
    RandomHandler(int seed);
    int seed;
    std::mt19937* engine;
};
}  // namespace MAP_GEN_LIB_NAMESPACE
#endif  // MAP_GEN_LIB_CORE_RANDOM_HANDLER_H
