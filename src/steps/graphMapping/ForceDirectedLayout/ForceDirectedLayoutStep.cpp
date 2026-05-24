#include "ForceDirectedLayoutStep.h"

#include <memory>
#include <vector>

#include "entities/graph/GraphPath.h"
#include "exceptions/NotImplementedException.h"
#include "helpers/Physics.h"
#include "helpers/RandomHandler.h"
#include "steps/graphMapping/ForceDirectedLayout/ForceDirectedLayoutOptions.h"
#include "steps/graphMapping/result/PhysicalBiome.h"

void MAP_GEN_LIB_NAMESPACE::Steps::ForceDirectedLayoutStep::init() {
    this->biomeCount = this->graph->getNodes().size();

    this->generationWidth = this->options->width - this->options->marginLeft - this->options->marginRight;
    this->generationHeight = this->options->height - this->options->marginBottom - this->options->marginTop;

    this->physicalBiomes.resize(biomeCount);
    this->positions.resize(biomeCount);
    for (size_t i = 0; i < biomeCount; ++i) {
        this->physicalBiomes[i] = std::make_shared<PhysicalBiome>(
            RandomHandler::get()->getRand<double>(0, generationWidth),
            RandomHandler::get()->getRand<double>(0, generationHeight), this->graph->getNodes()[i]->getBiome());
        this->positions[i][0] = physicalBiomes[i]->position[0];
        this->positions[i][1] = physicalBiomes[i]->position[1];
        this->reverseLookupMap[physicalBiomes[i]->biome] = i;
    }

    this->options->iterationCount = this->options->iterationCount.value_or(this->graph->getNodes().size());
}

void MAP_GEN_LIB_NAMESPACE::Steps::ForceDirectedLayoutStep::iterate() {
    for (size_t biomeAIdx = 0; biomeAIdx < biomeCount; biomeAIdx++) {
        for (size_t biomeBIdx = biomeAIdx + 1; biomeBIdx < biomeCount; biomeBIdx++) {
            auto diff = Helpers::Physics::repulsion<MAP_GEN_LIB_NAMESPACE::Entities::Vec<double, 2>>(
                this->options->repulsionConstant, physicalBiomes[biomeAIdx]->position,
                physicalBiomes[biomeBIdx]->position);

            for (size_t n = 0; n < diff.size(); ++n) {
                positions[biomeAIdx][n] += diff[n];
                positions[biomeBIdx][n] -= diff[n];
            }
        }
        // TODO: rewrite this - it makes no sense
        const std::vector<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Entities::GraphPath>> paths =
            this->graph->getNodes()[biomeAIdx]->getPathsTo();
        for (size_t pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
            auto diff = Helpers::Physics::attraction(
                this->options->attractionConstant, physicalBiomes[biomeAIdx]->position,
                physicalBiomes[reverseLookupMap[paths[pathIdx]->getTo()->getBiome()]]->position);
            positions[biomeAIdx][0] += diff[0];
            positions[biomeAIdx][1] += diff[1];
        }
    }
    for (size_t biomeIdx = 0; biomeIdx < biomeCount; biomeIdx++) {
        physicalBiomes[biomeIdx]->position[0] = positions[biomeIdx][0];
        physicalBiomes[biomeIdx]->position[1] = positions[biomeIdx][1];
        this->handleBorderStrategies(physicalBiomes[biomeIdx]->position);
    }
    ++(this->currentIteration);
}

void MAP_GEN_LIB_NAMESPACE::Steps::ForceDirectedLayoutStep::handleBorderStrategies(
    MAP_GEN_LIB_NAMESPACE::Entities::Vec<double, 2>& position) {
    switch (options->borderStrategy) {
        case MAP_GEN_LIB::Steps::ForceDirectedLayoutOptions::BorderStrategy::SLIDE:
            if (position[0] < 0) {
                position[0] = 0;
            } else if (position[0] >= this->generationWidth) {
                position[0] = this->generationWidth - 1;
            }

            if (position[1] < 0) {
                position[1] = 0;
            } else if (position[1] >= this->generationHeight) {
                position[1] = this->generationHeight - 1;
            }
            break;
        case ForceDirectedLayoutOptions::STOP:
            // TODO: implement
            throw Exceptions::NotImplementedException("Not yet implemented STOP border strategy");

            break;
        case ForceDirectedLayoutOptions::BOUNCE:
            while (position[0] < 0 || position[0] >= this->generationWidth || position[1] < 0 ||
                   position[1] >= this->generationHeight) {
                if (position[0] < 0) {
                    position[0] = -position[0];
                } else if (position[0] >= this->generationWidth) {
                    // NOTE: math somehow checks out
                    position[0] = this->generationWidth + this->generationWidth - 2 - position[0];
                }

                if (position[1] < 0) {
                    position[1] = -position[1];
                } else if (position[1] >= this->generationHeight) {
                    position[1] = this->generationHeight + this->generationHeight - 2 - position[1];
                }
            }
            break;
        default:
            // TODO: throw
            throw Exceptions::NotImplementedException("Not implemented the selected borderStartegy");
            break;
    }
}

std::vector<std::shared_ptr<MAP_GEN_LIB_NAMESPACE::Steps::PhysicalBiome>>
MAP_GEN_LIB_NAMESPACE::Steps::ForceDirectedLayoutStep::finish() {
    return this->physicalBiomes;
}
