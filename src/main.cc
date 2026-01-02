#include <argparse/argparse.hpp>

#include "silica.h"

int main(int argc, char** argv) {
  argparse::ArgumentParser program("silica");
  program.add_argument("-V", "--verbose")
      .help("include output helpful for debugging")
      .default_value(false)
      .implicit_value(true);
  program.add_argument("file")
      .help("silica file")
      .nargs(argparse::nargs_pattern::optional);

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  if (program.present("file")) {
    Silica::runFile(program.get<std::string>("file"),
                   program.get<bool>("verbose"));
  } else {
    Silica::repl(program.get<bool>("verbose"));
  }
  return 0;
}