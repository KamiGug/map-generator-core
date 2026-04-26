#include "Space2D.h"

#include <memory>

#include "exceptions/containers/OutOfSpaceBoundsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

Space2D::Space2D(std::unique_ptr<Space2DOptions> options) {
    if (options == nullptr) {
        options = std::make_unique<Space2DOptions>();
    }
    this->options = std::move(options);
    space = new std::shared_ptr<Cell>*[this->options->width];
    for (size_t i = 0; i < this->options->width; ++i) {
        space[i] = new std::shared_ptr<Cell>[this->options->height];
        for (size_t j = 0; j < this->options->height; j++) {
            space[i][j] = std::make_shared<Cell>(i, j);
        }
    }
}

Space2D::~Space2D() {
    for (size_t i = 0; i < this->options->width; ++i) {
        delete[] space[i];
    }
    delete[] space;
}
std::shared_ptr<Cell> Space2D::get(size_t x, size_t y) {
    if (x >= this->options->width || y >= this->options->height) {
        throw MAP_GEN_LIB_NAMESPACE::Exceptions::OutOfSpaceBoundsException("Out of space bounds");
    }
    return space[x][y];
}

// TODO: remove
// void Space2D::set(size_t x, size_t y, uint64_t value) {
//     if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
//         throw std::range_error("Out of space bounds");
//     }
//     space[x][y] = value;
// }

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
