#include "../include/CLI.hpp"
#include <iostream>

void CLI::registerCommand(const std::string& name,
                          const std::string& description,
                          CommandHandler handler) {
    commands_[name] = { description, handler };
}

std::vector<std::string> CLI::tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) tokens.push_back(token);
    return tokens;
}

void CLI::run() {
    std::string line;
    std::cout << "Embedded CLI v1.0. Type 'help' for a list of commands." << std::endl;
    while (std::cout << "> ", std::getline(std::cin, line)) {
        if (line.empty()) continue;
        auto args = tokenize(line);
        const auto& cmd = args[0];
        if (cmd == "exit" || cmd == "quit") {
            std::cout << "Exiting CLI..." << std::endl;
            break;
        }
        auto it = commands_.find(cmd);
        if (it != commands_.end()) {
            it->second.handler(args);
        } else {
            std::cout << "Unknown command: '" << cmd << "'. Type 'help'." << std::endl;
        }
    }
}

void CLI::registerDefaultCommands() {
    registerCommand("help", "Show available commands",
        [this](const std::vector<std::string>&) {
            std::cout << "Available commands:" << std::endl;
            for (const auto& [name, cmd] : commands_) {
                std::cout << "  " << name << " - " << cmd.description << std::endl;
            }
        });

    registerCommand("version", "Show firmware version",
        [](const std::vector<std::string>&) {
            std::cout << "Firmware v1.2.3 (Build 20250523)" << std::endl;
        });

    registerCommand("get", "Get a configuration parameter: get <param>",
        [](const std::vector<std::string>& args) {
            if (args.size() != 2) {
                std::cout << "Usage: get <param>" << std::endl;
                return;
            }
            std::cout << args[1] << " = <value>" << std::endl;
        });

    registerCommand("set", "Set a configuration parameter: set <param> <value>",
        [](const std::vector<std::string>& args) {
            if (args.size() != 3) {
                std::cout << "Usage: set <param> <value>" << std::endl;
                return;
            }
            std::cout << "Set " << args[1] << " to " << args[2] << std::endl;
        });

    registerCommand("status", "Show system status",
        [](const std::vector<std::string>&) {
            std::cout << "System Status: All systems nominal." << std::endl;
        });

    registerCommand("debug", "Enable or disable debug: debug <on|off>",
        [](const std::vector<std::string>& args) {
            if (args.size() != 2) {
                std::cout << "Usage: debug <on|off>" << std::endl;
                return;
            }
            if (args[1] == "on") std::cout << "Debug mode enabled." << std::endl;
            else if (args[1] == "off") std::cout << "Debug mode disabled." << std::endl;
            else std::cout << "Invalid option: use 'on' or 'off'." << std::endl;
        });

    registerCommand("reboot", "Reboot the system",
        [](const std::vector<std::string>&) {
            std::cout << "Rebooting system now..." << std::endl;
        });
}