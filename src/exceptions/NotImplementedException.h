#ifndef MAP_GEN_LIB_EXCEPTIONS_NOT_IMPLEMENTED_H
#define MAP_GEN_LIB_EXCEPTIONS_NOT_IMPLEMENTED_H

#include "MapGeneratorLibraryException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class NotImplementedException : public MapGeneratorLibraryException {
   public:
    NotImplementedException(std::string msg) : MapGeneratorLibraryException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_NOT_IMPLEMENTED_H
