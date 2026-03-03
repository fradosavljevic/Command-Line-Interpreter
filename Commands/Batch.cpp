#include "Batch.h"
#include <string>
#include "../Engine/InterpreterEngine.h"
#include "../Engine/Context.h"
#include <iostream>
using namespace std;

Batch::Batch(const Token &batchFile) : SingleFileCommand(batchFile) {
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

        InterpreterEngine::pushNewContext(ifs, new Context(inputStream, outputStream));
    } else {
        throw runtime_error("Greska! Fajl ne postoji!");
    }
}

string Batch::getHandle() {
    return handle;
}
