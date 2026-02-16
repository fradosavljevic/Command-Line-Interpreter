#include "Rm.h"
#include <string>
using namespace std;

Rm::Rm(const Token &filename, bool pipe) : SingleFileCommand(filename, pipe) {
    handle = "rm";
}

void Rm::execute() {
    const string filename = getFilename();
    if (filesystem::exists(filename)) {
        filesystem::remove_all(filename);
    } else {
        throw runtime_error("Greska! Fajl ne postoji.");
    }
}

string Rm::getHandle() {
    return handle;
}
