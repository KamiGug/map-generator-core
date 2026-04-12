#include "entities/graph/builders/tokens/GMLTokenizer.h"

#include <gtest/gtest.h>

#include <memory>
#include <sstream>

using namespace MAP_GEN_LIB_NAMESPACE::Entities;

TEST(GMLTokenizer, SimpleNode) {
    std::shared_ptr<std::istringstream> input = std::make_shared<std::istringstream>("node [ id 3 biomeId 1 ]");
    auto tokenizer = std::make_shared<GMLTokenizer>(input);

    auto t1 = tokenizer->nextToken();
    EXPECT_EQ(t1->type, Token::Type::Identifier);
    EXPECT_EQ(t1->value, "node");

    auto t2 = tokenizer->nextToken();
    EXPECT_EQ(t2->type, Token::Type::LBracket);

    auto t3 = tokenizer->nextToken();
    EXPECT_EQ(t3->type, Token::Type::Identifier);
    EXPECT_EQ(t3->value, "id");

    auto t4 = tokenizer->nextToken();
    EXPECT_EQ(t4->type, Token::Type::Number);
    EXPECT_EQ(t4->value, "3");
}

TEST(GMLTokenizer, SimpleNodeWithNewLines) {
    std::shared_ptr<std::istringstream> input = std::make_shared<std::istringstream>("node [\nid 3\nbiomeId 1\n]");
    auto tokenizer = std::make_shared<GMLTokenizer>(input);

    auto t1 = tokenizer->nextToken();
    EXPECT_EQ(t1->type, Token::Type::Identifier);
    EXPECT_EQ(t1->value, "node");

    auto t2 = tokenizer->nextToken();
    EXPECT_EQ(t2->type, Token::Type::LBracket);

    auto t3 = tokenizer->nextToken();
    EXPECT_EQ(t3->type, Token::Type::Identifier);
    EXPECT_EQ(t3->value, "id");

    auto t4 = tokenizer->nextToken();
    EXPECT_EQ(t4->type, Token::Type::Number);
    EXPECT_EQ(t4->value, "3");
}

TEST(GMLTokenizer, MultipleNewLines) {
    std::shared_ptr<std::istringstream> input = std::make_shared<std::istringstream>(
        "node \n\n\n\n\n[\n\n\n\n\n\nid\n\n\n\n\n\n\n\n3\n\n\n\n\n\nbiomeId\n\n\n\n\n\n1\n\n\n\n\n\n\n]");
    auto tokenizer = std::make_shared<GMLTokenizer>(input);
    auto t1 = tokenizer->nextToken();
    EXPECT_EQ(t1->type, Token::Type::Identifier);
    EXPECT_EQ(t1->value, "node");

    auto t2 = tokenizer->nextToken();
    EXPECT_EQ(t2->type, Token::Type::LBracket);

    auto t3 = tokenizer->nextToken();
    EXPECT_EQ(t3->type, Token::Type::Identifier);
    EXPECT_EQ(t3->value, "id");

    auto t4 = tokenizer->nextToken();
    EXPECT_EQ(t4->type, Token::Type::Number);
    EXPECT_EQ(t4->value, "3");
}
