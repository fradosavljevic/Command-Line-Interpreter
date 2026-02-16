#include "FileReader.h"
using namespace std;

FileReader::FileReader(const string &path) : Reader(&file), file(path) {
    if (!file.is_open()) throw runtime_error("Otvaranje fajla nije uspelo.");
}

string FileReader::readNewLine() {
    getline(*inputStream, line);
    return line;
}

std::string FileReader::readMultiLine() {
    string text;
    while (getline(*inputStream, line)) {
        text += (line + "\n");
    }
    inputStream->clear();
    return text;
}