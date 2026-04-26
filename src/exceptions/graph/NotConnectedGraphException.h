#ifndef MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_CONNECTED_GRAPH_H
#define MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_CONNECTED_GRAPH_H

#include "FailedToValidateGraph.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class NotConnectedGraphException : public FailedToValidateGraph {
   public:
    NotConnectedGraphException(std::string msg) : FailedToValidateGraph(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_CONNECTED_GRAPH_H
