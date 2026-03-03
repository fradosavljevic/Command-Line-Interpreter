#ifndef CLI_PIPE_H
#define CLI_PIPE_H
#include <memory>
#include <vector>
#include <sstream>

#include "Command.h"

// Klasa Pipe povezuje komande u cevovod i vrsi proveru validnosti datog izraza.
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