#ifndef CLI_STREAMREADER_H
#define CLI_STREAMREADER_H
#include "Reader.h"

// Klasa StreamReader je izvedena iz apstraktne klase Reader. Koristi se kada citamo sa nekog toka koji nije fajl ili standardni tok.
class StreamReader : public Reader {
public:
    StreamReader(std::istream* stream);

    std::string readNewLine() override;

    std::string readMultiLine() override;
};


#endif //CLI_STREAMREADER_H