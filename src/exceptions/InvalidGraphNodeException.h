#ifndef MAP_GEN_LIB_EXCEPTIONS_INVALID_GRAPH_NODE_H
#define MAP_GEN_LIB_EXCEPTIONS_INVALID_GRAPH_NODE_H

#include "BadArgumentsException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class InvalidGraphNodeException : public BadArgumentsException {
   public:
    InvalidGraphNodeException(std::string msg) : BadArgumentsException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_INVALID_GRAPH_NODE_H
