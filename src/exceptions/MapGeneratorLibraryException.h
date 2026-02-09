#ifndef MAP_GEN_LIB_EXCEPTIONS_BASE_H
#define MAP_GEN_LIB_EXCEPTIONS_BASE_H

#include <stdexcept>
#include <string>

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class MapGeneratorLibraryException : public std::runtime_error {
   public:
    MapGeneratorLibraryException(std::string msg) : std::runtime_error(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_BASE_H
