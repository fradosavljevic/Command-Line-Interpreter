#ifndef CLI_PIPE_H
#define CLI_PIPE_H
#include <memory>
#include <vector>
#include <sstream>

#include "Command.h"


class Pipe : public Command {
public:
    Pipe(std::vector<std::unique_ptr<Command>> commands);
    void execute() override;
    std::string getHandle() override;
private:
    std::vector<std::unique_ptr<Command>> Commands;
    std::stringstream BUFFER;
};


#endif