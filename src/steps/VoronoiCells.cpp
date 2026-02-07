#include "steps/VoronoiCells.h"

#include <cstddef>

#include "steps/VoronoiCellInitOptions.h"
namespace MAP_GEN_LIB_NAMESPACE::Steps {

VoronoiCell::VoronoiCell(VoronoiCellInitOptions* options) {
    bool rmOptions;
    if (options == nullptr) {
        rmOptions = true;
        options = new VoronoiCellInitOptions();
    } else {
        rmOptions = false;
    }
    this->cellCount = options->count;
    this->cellOriginPosition = new Entities::Vec<std::size_t>[this->cellCount];

    if (rmOptions) {
        delete options;
    }
}

void VoronoiCell::Transform(Entities::Space2D* space) {
    for (std::uint16_t i = 0; i < this->cellCount; ++i) {
        // this->cellOriginPosition[i].set(RandomHandler.getSize_t, RandomHandler.getSize_t);
    }
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
