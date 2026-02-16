#include "Batch.h"
#include <string>
#include "../Engine/InterpreterEngine.h"
#include <iostream>
using namespace std;

Batch::Batch(const Token &inputFile, bool pipe) : SingleFileCommand(inputFile, pipe) {
    handle = "batch";
}

void Batch::execute() {
    string file = getFilename();
    if (file.empty()) getline(*inputStream, file);
    if (filesystem::exists(file)) {
        auto* ifs = new ifstream(file);

        if (!ifs->is_open()) {
            delete ifs;
            throw runtime_error("Greska pri otvaranju fajla!");
        }

        InterpreterEngine::pushInputStream(ifs);
    } else {
        throw runtime_error("Greska! Fajl ne postoji!");
    }
}

string Batch::getHandle() {
    return handle;
}
