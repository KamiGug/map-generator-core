#ifndef MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H
#define MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H

#include <stdexcept>
#include <string>

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class BadArgumentsException : public std::runtime_error {
   public:
    BadArgumentsException(std::string msg) : std::runtime_error(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_BAD_ARGS_H
