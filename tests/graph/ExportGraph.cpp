#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "RandomHandler.h"
#include "entities/graph/Graph.h"
#include "entities/graph/builders/GMLBuilder.h"
#include "entities/graph/builders/GenerateTreeBuilder.h"
#include "entities/graph/exporters/GMLExporter.h"

TEST(Graph, GMLTreeExportAndImport) {
    MAP_GEN_LIB_NAMESPACE::RandomHandler::get(2000)->setSeed(2000);
    MAP_GEN_LIB_NAMESPACE::Entities::GenerateTreeBuilder treeBuilder;
    std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph> originalGraph =
        std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph>(treeBuilder.build());
    std::vector<std::string> graphGMLRepresentation =
        MAP_GEN_LIB_NAMESPACE::Entities::GMLExporter::transform(originalGraph.get());
    MAP_GEN_LIB_NAMESPACE::Entities::GMLBuilder gmlBuilder =
        MAP_GEN_LIB_NAMESPACE::Entities::GMLBuilder(graphGMLRepresentation);
    std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph> otherGraph =
        std::unique_ptr<MAP_GEN_LIB_NAMESPACE::Entities::Graph>(gmlBuilder.build());
    ASSERT_EQ(*originalGraph, *otherGraph);
}
