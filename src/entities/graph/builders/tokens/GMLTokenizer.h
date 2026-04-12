// entities/graph/builders/token/GMLTokenizer.h
#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_TOKENIZER_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_TOKENIZER_H

#include <istream>
#include <memory>
#include <queue>

#include "AbstractTokenizer.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

class GMLTokenizer : public AbstractTokenizer {
   public:
    explicit GMLTokenizer(std::shared_ptr<std::istream> in) : input(std::move(in)), line(1), column(0) {}

    std::unique_ptr<Token> nextToken() override;
    std::unique_ptr<Token> peekToken() override;

   private:
    std::shared_ptr<std::istream> input;
    size_t line;
    size_t column;

    std::queue<std::unique_ptr<Token>> lookahead;

    char peekChar();
    char getChar();
    void skipWhitespace();

    std::unique_ptr<Token> parseIdentifierOrKeyword();
    std::unique_ptr<Token> parseNumber();
    std::unique_ptr<Token> parseString();
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_GML_TOKENIZER_H
