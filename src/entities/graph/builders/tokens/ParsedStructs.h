#ifndef MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_PARSED_STRUCTS_H
#define MAP_GEN_LIB_ENTITIES_GRAPH_BUILDERS_PARSED_STRUCTS_H

#include <string>

namespace MAP_GEN_LIB_NAMESPACE::Entities {

struct ParsedNode {
    int id;
    int biomeId;
};

struct ParsedEdge {
    int sourceId;
    int targetId;
    bool bidirectional = true;
};

struct ParsedBiome {
    int id;
    std::string pathToTileMap;
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
#endif
