#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKENIZER_BUILDER_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKENIZER_BUILDER_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "AbstractGraphBuilder.h"
#include "entities/Biome.h"
#include "entities/BiomeOptions.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "entities/graph/GraphOptions.h"
#include "entities/graph/GraphPathOptions.h"
#include "tokens/AbstractTokenizer.h"
#include "tokens/ParsedStructs.h"
#include "tokens/Token.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

template <TokenizerConcept TokenizerClass>
class TokenizerBuilder : public AbstractGraphBuilder {
   public:
    explicit TokenizerBuilder(std::shared_ptr<std::istream> input)
        : tokenizer(std::make_unique<TokenizerClass>(std::move(input))) {}

    std::unique_ptr<Graph> build(std::unique_ptr<GraphOptions> options = nullptr) override {
        parseTokens();
        return buildGraph(std::move(options));
    }

   private:
    std::unique_ptr<TokenizerClass> tokenizer;

    std::vector<ParsedBiome> biomes;
    std::vector<ParsedNode> nodes;
    std::vector<ParsedEdge> edges;

    void parseTokens() {
        while (auto token = tokenizer->nextToken()) {
            if (token->type != Token::Type::Identifier) continue;

            if (token->value == "biome") {
                parseBiome();
            } else if (token->value == "node") {
                parseNode();
            } else if (token->value == "edge") {
                parseEdge();
            } else {
                // Ignore unknown identifiers for now
            }
        }
    }

    void parseBiome() {
        expect(Token::Type::LBracket);
        ParsedBiome b;
        while (auto t = tokenizer->nextToken()) {
            if (t->type == Token::Type::RBracket) break;

            if (t->type != Token::Type::Identifier) continue;

            if (t->value == "id") {
                b.id = std::stoi(expect(Token::Type::Number)->value);
            } else if (t->value == "pathToTileMap") {
                b.pathToTileMap = expect(Token::Type::String)->value;
            } else {
                skipValue();
            }
        }
        biomes.push_back(b);
    }

    void parseNode() {
        expect(Token::Type::LBracket);
        ParsedNode n{};
        while (auto t = tokenizer->nextToken()) {
            if (t->type == Token::Type::RBracket) break;

            if (t->type != Token::Type::Identifier) continue;

            if (t->value == "id") {
                n.id = std::stoi(expect(Token::Type::Number)->value);
            } else if (t->value == "biomeId") {
                n.biomeId = std::stoi(expect(Token::Type::Number)->value);
            } else {
                skipValue();
            }
        }
        nodes.push_back(n);
    }

    void parseEdge() {
        expect(Token::Type::LBracket);
        ParsedEdge e{};
        while (auto t = tokenizer->nextToken()) {
            if (t->type == Token::Type::RBracket) break;

            if (t->type != Token::Type::Identifier) continue;

            if (t->value == "source") {
                e.sourceId = std::stoi(expect(Token::Type::Number)->value);
            } else if (t->value == "target") {
                e.targetId = std::stoi(expect(Token::Type::Number)->value);
            } else if (t->value == "bidirectional") {
                e.bidirectional = std::stoi(expect(Token::Type::Number)->value) != 0;
                std::cout << e.bidirectional;
            } else {
                skipValue();
            }
        }
        edges.push_back(e);
    }

    std::unique_ptr<Token> expect(Token::Type type) {
        auto t = tokenizer->nextToken();
        if (!t) throw std::runtime_error("Unexpected EOF while expecting token");
        if (t->type != type) throw std::runtime_error("Unexpected token type");
        return t;
    }

    void skipValue() { tokenizer->nextToken(); }

    std::unique_ptr<Graph> buildGraph(std::unique_ptr<GraphOptions> options = nullptr) {
        if (options == nullptr) {
            options = std::make_unique<GraphOptions>();
            options->autoValidate = false;
            options->throwOnFailedAutoValidation = true;
            options->throwOnFailedExplicitValidation = true;
        }
        auto g = std::make_unique<Graph>(std::move(options));

        std::unordered_map<int, std::shared_ptr<Biome>> biomeMap;
        for (const auto& pb : biomes) {
            auto options = std::make_unique<BiomeOptions>();
            options->setPathToTileMap(pb.pathToTileMap);
            auto biome = std::make_shared<Biome>(options.release());
            biomeMap[pb.id] = biome;
        }

        std::unordered_map<int, std::shared_ptr<GraphNode>> nodeMap;
        for (const auto& pn : nodes) {
            auto it = biomeMap.find(pn.biomeId);
            if (it == biomeMap.end()) throw std::runtime_error("Unknown biomeId for node");
            auto node = std::make_shared<GraphNode>(it->second);
            nodeMap[pn.id] = node;
            g->addNode(node);
        }

        for (const auto& pe : edges) {
            auto fromIt = nodeMap.find(pe.sourceId);
            auto toIt = nodeMap.find(pe.targetId);
            std::unique_ptr<GraphPathOptions> pathOptions = std::make_unique<GraphPathOptions>();
            pathOptions->setBidirectional(pe.bidirectional);
            if (fromIt == nodeMap.end() || toIt == nodeMap.end()) throw std::runtime_error("Unknown nodeId in edge");
            g->addPath(fromIt->second, toIt->second, std::move(pathOptions));
        }

        return g;
    }
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities

#endif  // MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_TOKENIZER_BUILDER_H
