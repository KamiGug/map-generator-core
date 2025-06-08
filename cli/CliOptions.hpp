#ifndef MAP_GEN_LIB_CLI_OPTIONS_H
#define MAP_GEN_LIB_CLI_OPTIONS_H

#include "../src/Options.hpp"
#include <CLI/CLI.hpp>

namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER {
class CliOptions {
public:
  static bool quiet;
  CliOptions(CLI::App *app);

  MAP_GEN_LIB_NAMESPACE::Options *getOptions();

private:
  CLI::App *app;
  std::optional<std::string> pathToFile;
  std::optional<int> seed;

  void setupOptions();
};
} // namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER

#endif
