#ifndef MAP_GEN_LIB_STEPS_VORONOI_CELL_H
#define MAP_GEN_LIB_STEPS_VORONOI_CELL_H

#include <cstddef>
#include <cstdint>

#include "entities/containers/Vec.h"
#include "steps/AbstractStep.h"
#include "steps/VoronoiCellInitOptions.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class VoronoiCell : public AbstractStep {
   public:
    VoronoiCell(VoronoiCellInitOptions* options = nullptr);
    void Transform(Entities::Space2D* space);

   private:
    std::uint16_t cellCount;
    Entities::Vec<size_t>* cellOriginPosition;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_VORONOI_CELL_H
