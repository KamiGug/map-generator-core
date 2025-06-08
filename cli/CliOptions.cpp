#include "CliOptions.hpp"
#include <CLI/CLI.hpp>

namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER {
CliOptions::CliOptions(CLI::App *app) {
  this->app = app;
  setupOptions();
}

void CliOptions::setupOptions() {
  this->app->add_option(
      "-f,--file", this->pathToFile,
      "Select file that contains key-value pairs of settings for the options");
  this->app->add_option("-s,--seed", this->seed,
                        "Choose seed for random number generation");
  this->app->add_flag("-q,--quiet", CliOptions::quiet,
                      "Make this less verbose");
}
} // namespace MAP_GEN_LIB_NAMESPACE::CLI_WRAPPER
