#ifndef MAP_GEN_LIB_ENTITIES_CONTAINER_VECTOR_H
#define MAP_GEN_LIB_ENTITIES_CONTAINER_VECTOR_H

#include <array>
#include <cmath>
#include <concepts>
#include <cstddef>

namespace MAP_GEN_LIB_NAMESPACE::Entities {
template <typename T>
concept ArithmeticCoord = (std::integral<T> && !std::same_as<T, bool>) || std::floating_point<T>;

template <ArithmeticCoord T = double, size_t N = 2>
class Vec {
   public:
    using is_vec_tag = void;
    static_assert(N > 0, "Vec dimension must be > 0");

    // Constructors
    constexpr Vec() = default;

    constexpr explicit Vec(const std::array<T, N>& values) : v(values) {}

    // Access operators
    constexpr T& operator[](std::size_t i) { return v[i]; }
    constexpr const T& operator[](std::size_t i) const { return v[i]; }

    // Compound operators
    constexpr Vec& operator+=(const Vec& other) {
        for (std::size_t i = 0; i < N; ++i) v[i] += other.v[i];
        return *this;
    }

    constexpr Vec& operator-=(const Vec& other) {
        for (std::size_t i = 0; i < N; ++i) v[i] -= other.v[i];
        return *this;
    }

    constexpr Vec& operator*=(T scalar) {
        for (std::size_t i = 0; i < N; ++i) v[i] *= scalar;
        return *this;
    }

    constexpr Vec& operator/=(T scalar) {
        for (std::size_t i = 0; i < N; ++i) v[i] /= scalar;
        return *this;
    }

    constexpr double length_sq() const {
        double sum = 0.0;
        for (std::size_t i = 0; i < N; ++i) sum += static_cast<double>(v[i]) * static_cast<double>(v[i]);
        return sum;
    }

    inline double length() const { return std::sqrt(length_sq()); }

    constexpr size_t size() const { return N; }

    inline void normalize() {
        bool zeroLen = true;
        for (size_t i = 0; i < N; ++i) {
            if (v != 0) {
                zeroLen = false;
                break;
            }
        }
        if (zeroLen) {
            return;
        }
        T len = this->length();
        for (size_t i = 0; i < N; ++i) {
            v[i] /= len;
        }
    }

   private:
    std::array<T, N> v{};
};

template <typename T>
concept VecConcept = requires { typename T::is_vec_tag; };

template <ArithmeticCoord T, std::size_t N>
constexpr Vec<T, N> operator+(Vec<T, N> a, const Vec<T, N>& b) {
    return a += b;
}

template <ArithmeticCoord T, std::size_t N>
constexpr Vec<T, N> operator-(Vec<T, N> a, const Vec<T, N>& b) {
    return a -= b;
}

template <ArithmeticCoord T, std::size_t N>
constexpr Vec<T, N> operator*(Vec<T, N> a, T scalar) {
    return a *= scalar;
}

template <ArithmeticCoord T, std::size_t N>
constexpr Vec<T, N> operator*(T scalar, Vec<T, N> a) {
    return a *= scalar;
}

template <ArithmeticCoord T, std::size_t N>
constexpr Vec<T, N> operator/(Vec<T, N> a, T scalar) {
    return a /= scalar;
}

template <ArithmeticCoord T, std::size_t N>
constexpr double dot(const Vec<T, N>& a, const Vec<T, N>& b) {
    double sum = 0.0;
    for (std::size_t i = 0; i < N; ++i) sum += static_cast<double>(a[i]) * static_cast<double>(b[i]);
    return sum;
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_CONTAINER_VECTOR_H
