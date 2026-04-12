#include "GMLTokenizer.h"

#include <cctype>
#include <stdexcept>

namespace MAP_GEN_LIB_NAMESPACE::Entities {

char GMLTokenizer::peekChar() { return input->peek(); }

char GMLTokenizer::getChar() {
    char c = input->get();
    if (c == '\n') {
        ++line;
        column = 0;
    } else {
        ++column;
    }
    return c;
}

void GMLTokenizer::skipWhitespace() {
    while (input->good() && std::isspace(peekChar())) {
        getChar();
    }
}

std::unique_ptr<Token> GMLTokenizer::parseIdentifierOrKeyword() {
    std::string value;
    size_t startColumn = column + 1;

    while (input->good()) {
        char c = peekChar();
        if (std::isalnum(c) || c == '_' || c == '-') {
            value += getChar();
        } else {
            break;
        }
    }

    return std::make_unique<Token>(Token::Type::Identifier, value, line, startColumn);
}

std::unique_ptr<Token> GMLTokenizer::parseNumber() {
    std::string value;
    size_t startColumn = column + 1;

    while (input->good()) {
        char c = peekChar();
        if (std::isdigit(c) || c == '.') {
            value += getChar();
        } else {
            break;
        }
    }

    return std::make_unique<Token>(Token::Type::Number, value, line, startColumn);
}

std::unique_ptr<Token> GMLTokenizer::parseString() {
    std::string value;
    size_t startColumn = column + 1;

    getChar();
    while (input->good()) {
        char c = getChar();
        if (c == '"') break;
        if (c == '\\') {
            char next = getChar();
            value += next;
        } else {
            value += c;
        }
    }

    return std::make_unique<Token>(Token::Type::String, value, line, startColumn);
}

std::unique_ptr<Token> GMLTokenizer::nextToken() {
    if (!lookahead.empty()) {
        auto tok = std::move(lookahead.front());
        lookahead.pop();
        return tok;
    }

    skipWhitespace();

    if (!input->good()) return nullptr;

    char c = peekChar();

    if (c == '[') {
        getChar();
        return std::make_unique<Token>(Token::Type::LBracket, "", line, column);
    } else if (c == ']') {
        getChar();
        return std::make_unique<Token>(Token::Type::RBracket, "", line, column);
    } else if (c == '"') {
        return parseString();
    } else if (std::isdigit(c) || c == '-') {
        return parseNumber();
    } else if (std::isalpha(c) || c == '_') {
        return parseIdentifierOrKeyword();
    }

    throw std::runtime_error("Unexpected character '" + std::string(1, c) + "' at line " + std::to_string(line) +
                             " column " + std::to_string(column));
}

std::unique_ptr<Token> GMLTokenizer::peekToken() {
    if (lookahead.empty()) {
        auto tok = nextToken();
        if (tok) lookahead.push(std::move(tok));
    }
    if (lookahead.empty()) return nullptr;
    return std::make_unique<Token>(*lookahead.front());
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
