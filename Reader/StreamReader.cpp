#include "StreamReader.h"
#include <iostream>
using namespace std;

StreamReader::StreamReader(std::istream *stream) : Reader(stream) {}

std::string StreamReader::readNewLine() {
    if (!getline(*inputStream, line)) return "";
    return line;
}

std::string StreamReader::readMultiLine() {
    string text;
    while (getline(*inputStream, line)) {
        text += (line + "\n");
    }
    inputStream->clear();
    return text;
}
