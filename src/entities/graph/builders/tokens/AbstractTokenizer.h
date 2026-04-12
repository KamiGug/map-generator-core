#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_TOKENIZER_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_TOKENIZER_H

#include <memory>

#include "Token.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class AbstractTokenizer {
   public:
    virtual ~AbstractTokenizer() = default;

    // Returns the next token or nullptr if EOF
    virtual std::unique_ptr<Token> nextToken() = 0;

    // Optional: peek at the next token
    virtual std::unique_ptr<Token> peekToken() = 0;
};

template <typename T>
concept TokenizerConcept = std::derived_from<T, AbstractTokenizer>;

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_ABSTRACT_TOKENIZER_H
