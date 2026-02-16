#include "Touch.h"
using namespace std;

Touch::Touch(const Token &filename, bool pipe) : SingleFileCommand(filename, pipe) {}

void Touch::execute() {
    string fileName = getFilename();
    if (fileName.empty()) getline(*inputStream, fileName);
    if (filesystem::exists(fileName)) {
        throw runtime_error("Greska! Fajl vec postoji!");
    }
    ofstream file(fileName);
}

std::string Touch::getHandle() {
    return handle;
}
