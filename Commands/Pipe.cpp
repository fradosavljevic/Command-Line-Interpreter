#include "Pipe.h"
#include <iostream>

Pipe::Pipe(std::vector<std::unique_ptr<Command>> commands) : Command(nullptr, nullptr), Commands(std::move(commands)) {
    handle = "none";
}

void Pipe::execute() {
    const size_t cmdSize = Commands.size();
    std::tuple<bool, bool, bool> commandState = Commands[0]->getState();
    if (std::get<1>(commandState))
        throw std::runtime_error("Nije dozvoljena output redirekcija na pocetku pipe-a");

    Commands[0]->setOutputStream(&BUFFER);
    Commands[0]->execute();

    for (int i = 1; i < cmdSize - 1; i++) {
        commandState = Commands[i]->getState();
        if (std::get<0>(commandState) || std::get<1>(commandState))
            throw std::runtime_error("Nisu dozvoljene redirekcije unutar pipe-a");

        Commands[i]->setInputStream(&BUFFER);
        Commands[i]->setOutputStream(&BUFFER);
        Commands[i]->execute();
    }

    commandState = Commands[cmdSize - 1]->getState();
    if (std::get<0>(commandState))
        throw std::runtime_error("Nije dozvoljena input redirekcija na kraju pipe-a");

    Commands[cmdSize - 1]->setInputStream(&BUFFER);
    Commands[cmdSize - 1]->execute();
}

std::string Pipe::getHandle() {
    return handle;
}
