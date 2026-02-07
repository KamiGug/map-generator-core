#include "WorldGenerator.h"

#include <memory>

#include "Options.h"
#include "RandomHandler.h"

namespace MAP_GEN_LIB_NAMESPACE {

WorldGenerator::WorldGenerator(std::unique_ptr<Options> options) {
    RandomHandler::get(options->getSeed());

    this->options = std::move(options);
    this->options->setGenerator(this);
}

}  // namespace MAP_GEN_LIB_NAMESPACE
