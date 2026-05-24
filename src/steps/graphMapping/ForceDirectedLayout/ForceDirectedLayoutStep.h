#ifndef MAP_GEN_LIB_STEPS_FORCE_DIRECTED_LAYOUT_STEP_H
#define MAP_GEN_LIB_STEPS_FORCE_DIRECTED_LAYOUT_STEP_H

#include <map>
#include <memory>
#include <vector>

#include "ForceDirectedLayoutOptions.h"
#include "steps/graphMapping/AbstractGraphPlacementStep.h"
#include "steps/graphMapping/result/PhysicalBiome.h"

namespace MAP_GEN_LIB_NAMESPACE::Steps {

class ForceDirectedLayoutStep : public AbstractGraphPlacementStep {
   public:
    inline ForceDirectedLayoutStep(std::shared_ptr<Entities::Graph> graph,
                                   std::shared_ptr<ForceDirectedLayoutOptions> options = nullptr)
        : AbstractGraphPlacementStep(graph) {
        if (options == nullptr) {
            this->options = std::make_shared<ForceDirectedLayoutOptions>();
        } else {
            this->options = options;
        }
    }

    inline std::vector<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Steps::PhysicalBiome>> transform() {
        this->init();
        while (currentIteration < this->options->iterationCount.value()) {
            iterate();
        }
        return this->finish();
    };

    void init();
    void iterate();
    std::vector<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Steps::PhysicalBiome>> finish();
    void handleBorderStrategies(MAP_GEN_LIB_NAMESPACE::Entities::Vec<double, 2>& position);

    size_t currentIteration = 0;
    std::vector<std::shared_ptr<PhysicalBiome>> physicalBiomes;

   protected:
    size_t biomeCount;
    double generationWidth;
    double generationHeight;
    std::vector<MAP_GEN_LIB_NAMESPACE::Entities::Vec<double, 2>> positions;
    std::map<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Biome>, size_t> reverseLookupMap;
    std::shared_ptr<ForceDirectedLayoutOptions> options;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_FORCE_DIRECTED_LAYOUT_STEP_H
