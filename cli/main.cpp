#include <CLI/CLI.hpp>

#include "RandomHandler.h"
#include "entities/graph/Graph.h"
#include "entities/graph/builders/GenerateTreeBuilder.h"
#include "test.h"

using namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER;

int main(int argc, char** argv) {
    CLI::App app{MAP_GEN_LIB_NAME_STR};

    int seed = 0;
    app.add_option("-s,--seed", seed, "Random seed");
    CLI11_PARSE(app, argc, argv);

    MAP_GEN_LIB::RandomHandler::get(seed);

    MAP_GEN_LIB::Entities::GenerateTreeBuilder builder;
    MAP_GEN_LIB::Entities::Graph* graph = builder.build();

    test();

    return 0;
}
