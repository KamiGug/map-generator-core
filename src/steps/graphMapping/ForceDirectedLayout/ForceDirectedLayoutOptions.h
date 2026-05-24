#ifndef MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_OPTIONS_H
#define MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_OPTIONS_H

#include <optional>
namespace MAP_GEN_LIB_NAMESPACE::Steps {

class ForceDirectedLayoutOptions {
   public:
    enum BorderStrategy { SLIDE, STOP, BOUNCE };
    inline ForceDirectedLayoutOptions() {}

    double attractionConstant = 0.4932;

    double repulsionConstant = 0.34636;

    // NOTE: std::nullopt -> iteration count == node count
    std::optional<size_t> iterationCount = std::nullopt;

    double marginTop = 0;
    double marginBottom = 0;
    double marginLeft = 0;
    double marginRight = 0;

    double width;
    double height;

    BorderStrategy borderStrategy = BorderStrategy::SLIDE;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Steps
#endif  // MAP_GEN_LIB_STEPS_ABSTRACT_GRAPH_PLACEMENT_OPTIONS_H
