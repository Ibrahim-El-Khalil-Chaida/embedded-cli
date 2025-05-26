## include/CLI.hpp
#ifndef CLI_HPP
#define CLI_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <sstream>

class CLI {
public:
    using CommandHandler = std::function<void(const std::vector<std::string>&)>;

    void registerCommand(const std::string& name,
                         const std::string& description,
                         CommandHandler handler);
    void run();

private:
    struct Command {
        std::string description;
        CommandHandler handler;
    };
    std::unordered_map<std::string, Command> commands_;
    std::vector<std::string> tokenize(const std::string& input);

public:
    void registerDefaultCommands();
};

#endif 
