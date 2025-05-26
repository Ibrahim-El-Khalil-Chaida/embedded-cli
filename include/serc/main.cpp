#include "../include/CLI.hpp"

int main() {
    CLI cli;
    cli.registerDefaultCommands();
    cli.run();
    return 0;
}
