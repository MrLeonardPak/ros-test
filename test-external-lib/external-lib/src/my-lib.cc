#include "external-lib/my-lib.hh"

#include "cli/cli.h"
#include "cli/clifilesession.h"

using namespace cli;
using namespace std;

void Consol::Run(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  auto rootMenu = make_unique<Menu>("cli");
  rootMenu->Insert(
      "hello", [](std::ostream& out) { out << "Hello, world\n"; },
      "Print hello world");
  rootMenu->Insert(
      "hello_everysession",
      [](std::ostream&) { Cli::cout() << "Hello, everybody" << std::endl; },
      "Print hello everybody on all open sessions");
  rootMenu->Insert(
      "answer",
      [](std::ostream& out, int x) { out << "The answer is: " << x << "\n"; },
      "Print the answer to Life, the Universe and Everything ");
  rootMenu->Insert(
      "color",
      [](std::ostream& out) {
        out << "Colors ON\n";
        SetColor();
      },
      "Enable colors in the cli");
  rootMenu->Insert(
      "nocolor",
      [](std::ostream& out) {
        out << "Colors OFF\n";
        SetNoColor();
      },
      "Disable colors in the cli");

  Cli cli(std::move(rootMenu));
  // global exit action
  cli.ExitAction([](auto& out) {
    out << "Goodbye and thanks for all the fish.\n";
    rclcpp::shutdown();
  });

  CliFileSession input(cli);
  input.Start();
}
