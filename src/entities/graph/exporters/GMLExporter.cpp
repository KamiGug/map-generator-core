#include "GMLExporter.h"

#include <memory>
#include <set>
#include <string>
#include <unordered_map>

#include "entities/Biome.h"
#include "entities/graph/Graph.h"
#include "entities/graph/GraphNode.h"
#include "exceptions/InvalidGraphException.h"

namespace MAP_GEN_LIB_NAMESPACE::Entities {

void GMLExporter::write(Graph& graph, std::ostream& out) {
    if (!graph.validate()) {
        throw Exceptions::InvalidGraphException("Tried to write a graph that is not valid");
    }
    out << "graph [\n";

    // write any graph related settings, like:
    // out << GMLExporter::indent(1) + "seed " + std::to_string(MAP_GEN_LIB_NAMESPACE::RandomHandler::get()->getSeed())
    // + "\n";
    out << GMLExporter::indent(1) << "autoValidate " << (graph.autoValidate ? "1" : "0") << "\n";

    auto nodes = graph.getNodes();
    auto nodeCount = nodes.size();

    std::unordered_map<GraphNode*, size_t> nodeIds;
    std::set<std::shared_ptr<Biome>> biomes;

    // NODES
    for (size_t i = 0; i < nodeCount; i++) {
        nodeIds[nodes[i].get()] = i;
        biomes.insert(nodes[i]->getBiome());
        out << GMLExporter::indent(1) << "node [\n";
        out << GMLExporter::indent(2) << "id " << std::to_string(i) << "\n";
        out << GMLExporter::indent(2) << "biomeId " << std::to_string(nodes[i]->getBiome()->getId()) << "\n";
        out << GMLExporter::indent(1) << "]\n";
    }

    // PATHS
    for (const auto& path : graph.getPaths()) {
        if (!path) continue;
        auto from = path->getFrom();
        auto to = path->getTo();

        if (!from || !to) continue;

        out << GMLExporter::indent(1) << "edge [\n";
        out << GMLExporter::indent(2) << "source " << nodeIds[from.get()] << "\n";
        out << GMLExporter::indent(2) << "target " << nodeIds[to.get()] << "\n";
        out << GMLExporter::indent(2) << "bidirectional " << path->isBidirectional() << "\n";
        out << GMLExporter::indent(1) << "]\n";
    }

    for (auto biome : biomes) {
        out << GMLExporter::indent(1) << "biome [\n";
        out << GMLExporter::indent(2) << "id " << biome->getId() << "\n";
        out << GMLExporter::indent(2) << "pathToTileMap \"" << biome->getOptions().getPathToTileMap() << "\"\n";
        out << GMLExporter::indent(1) << "]\n";
    }

    out << "]";
    out << "\n";
}

}  // namespace MAP_GEN_LIB_NAMESPACE::Entities
