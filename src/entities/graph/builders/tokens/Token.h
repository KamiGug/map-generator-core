#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKEN_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKEN_H

#include <cstddef>
#include <string>

namespace MAP_GEN_LIB_NAMESPACE::Entities {

// Atomic syntactic token
struct Token {
    enum class Type { Identifier, Number, String, LBracket, RBracket };

    Type type;
    std::string value;  // e.g., "node", "3", "forest"
    size_t line;        // for error reporting
    size_t column;

    Token(Type t, std::string v, size_t l, size_t c) : type(t), value(std::move(v)), line(l), column(c) {}
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKEN_H
