#include "test.hpp"
#include <CLI/CLI.hpp>

using namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER;

int main(int argc, char **argv) {
  CLI::App app{MAP_GEN_LIB_NAME_STR};

  int seed = 0;
  app.add_option("-s,--seed", seed, "Random seed");

  CLI11_PARSE(app, argc, argv);
  test();

  return 0;
}
