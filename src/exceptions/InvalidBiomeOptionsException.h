#ifndef MAP_GEN_LIB_EXCEPTIONS_INVALID_BIOME_OPTIONS_H
#define MAP_GEN_LIB_EXCEPTIONS_INVALID_BIOME_OPTIONS_H

#include "BadArgumentsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class InvalidBiomeOptionsException : public BadArgumentsException {
   public:
    InvalidBiomeOptionsException(std::string msg) : BadArgumentsException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_INVALID_BIOME_OPTIONS_H
