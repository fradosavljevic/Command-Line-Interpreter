#include "Truncate.h"
#include <string>
using namespace std;

Truncate::Truncate(const Token &filename, bool pipe) : SingleFileCommand(filename, pipe) {
    handle = "truncate";
}

void Truncate::execute() {
    const string filename = getFilename();
    if (filesystem::exists(filename)) {
        ofstream t(filename, ofstream::trunc | ofstream::out);
    } else {
        throw runtime_error("Greska! Fajl ne postoji.");
    }
}

std::string Truncate::getHandle() {
    return handle;
}

