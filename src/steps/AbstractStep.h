#ifndef MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H
#define MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H

#include "entities/containers/Space2D.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class AbstractStep {
   public:
    void virtual Transform(Entities::Space2D* space);
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_ABSTRACT_STEP_H
