#include "ConsoleReader.h"
#include <iostream>
using namespace std;

ConsoleReader::ConsoleReader() : Reader(&cin) {};

string ConsoleReader::readNewLine() {
    if (!getline(*inputStream, line)) return "";

    if (line.size() > MAX_LINE_SIZE) {
        line = line.substr(0, MAX_LINE_SIZE);
    }

    return line;
}

string ConsoleReader::readMultiLine() {
    string text;
    while (getline(*inputStream, line)) {
        text += (line + "\n");
    }
    inputStream->clear();
    return text;
}
