#ifndef MAP_GEN_LIB_EXCEPTIONS_OUT_OF_SPACE_BOUNDS_EXCEPTION_H
#define MAP_GEN_LIB_EXCEPTIONS_OUT_OF_SPACE_BOUNDS_EXCEPTION_H

#include "exceptions/BadArgumentsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class OutOfSpaceBoundsException : public BadArgumentsException {
   public:
    OutOfSpaceBoundsException(std::string msg) : BadArgumentsException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_OUT_OF_SPACE_BOUNDS_EXCEPTION_H
