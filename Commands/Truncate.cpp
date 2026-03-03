#include "Truncate.h"
#include <string>
using namespace std;

Truncate::Truncate(const Token &filename) : SingleFileCommand(filename) {
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

