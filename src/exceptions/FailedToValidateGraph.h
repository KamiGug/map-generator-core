#ifndef MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_GRAPH_H
#define MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_GRAPH_H

#include "MapGeneratorLibraryException.h"

namespace MAP_GEN_LIB_NAMESPACE::Exceptions {
class FailedToValidateGraph : public MapGeneratorLibraryException {
   public:
    FailedToValidateGraph(std::string msg) : MapGeneratorLibraryException(msg) {}
};
}  // namespace MAP_GEN_LIB_NAMESPACE::Exceptions

#endif  // MAP_GEN_LIB_EXCEPTIONS_FAILED_TO_VALIDATE_GRAPH_H
