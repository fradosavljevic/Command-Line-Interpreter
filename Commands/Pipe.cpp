#include "Pipe.h"
#include <iostream>

Pipe::Pipe(std::vector<std::unique_ptr<Command>> commands) : Command(nullptr, nullptr), Commands(std::move(commands)) {
    handle = "none";
}

void Pipe::execute() {
    Commands[0]->setOutputStream(&BUFFER);
    Commands[0]->execute();
    for (int i = 1; i < Commands.size() - 1; i++) {
        Commands[i]->setInputStream(&BUFFER);
        Commands[i]->setOutputStream(&BUFFER);
        Commands[i]->execute();
    }
    Commands[Commands.size() - 1]->setInputStream(&BUFFER);
    Commands[Commands.size() - 1]->setOutputStream(&std::cout);
    Commands[Commands.size() - 1]->execute();
}

std::string Pipe::getHandle() {
    return handle;
}
