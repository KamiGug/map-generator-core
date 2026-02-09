#ifndef MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H
#define MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H

#include "MapGeneratorLibraryException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class BadArgumentsException : public MapGeneratorLibraryException {
   public:
    BadArgumentsException(std::string msg) : MapGeneratorLibraryException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H
