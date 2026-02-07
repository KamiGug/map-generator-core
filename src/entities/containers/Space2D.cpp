#include "Space2D.h"

#include <cstdint>
#include <stdexcept>

namespace MAP_GEN_LIB_NAMESPACE::Entities {

Space2D::Space2D(Space2DInitOptions* options) {
    bool rmOptions;
    if (options == nullptr) {
        rmOptions = true;
        options = new Space2DInitOptions();
    } else {
        rmOptions = false;
    }
    this->width = options->width;
    this->height = options->height;
    space = new uint64_t*[this->width];
    for (size_t i = 0; i < this->width; ++i) {
        space[i] = new uint64_t[this->height];
    }
    if (rmOptions) delete options;
}

Space2D::~Space2D() {
    for (size_t i = 0; i < this->width; ++i) {
        delete[] space[i];
    }
    delete[] space;
}
uint64_t Space2D::get(size_t x, size_t y) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::range_error("Out of space bounds");
    }
    return space[x][y];
}

void Space2D::set(size_t x, size_t y, uint64_t value) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::range_error("Out of space bounds");
    }
    space[x][y] = value;
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
