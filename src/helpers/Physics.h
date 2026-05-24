#ifndef MAP_GEN_LIB_HELPERS_PHYSICS_H
#define MAP_GEN_LIB_HELPERS_PHYSICS_H

#include "entities/containers/Vec.h"

namespace MAP_GEN_LIB_NAMESPACE::Helpers {

class Physics {
   public:
    template <Entities::VecConcept VectorType>
    static VectorType repulsion(double repulsionConstant, const VectorType& positionA, const VectorType& positionB,
                                double strengthA = 1.0, double strengthB = 1.0) {
        // r
        VectorType result = positionA - positionB;
        double distance = result.length();
        if (distance == 0) {
            return VectorType();
        }
        // k * q1 * q2 * r
        result *= repulsionConstant * strengthA * strengthB;
        // (k * q1 * q2) / (r ^ 2)
        result /= distance * distance * distance;
        return result;
    }

    template <Entities::VecConcept VectorType>
    static VectorType attraction(double attractionConstant, const VectorType& positionA, const VectorType& positionB) {
        VectorType result = positionB - positionA;
        if (result.length() == 0) {
            return VectorType();
        }
        result *= attractionConstant;
        return result;
    }
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Helpers
#endif  // MAP_GEN_LIB_HELPERS_PHYSICS_H
