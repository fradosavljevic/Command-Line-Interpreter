#ifndef CLI_CONSOLEREADER_H
#define CLI_CONSOLEREADER_H
#include "Reader.h"

// Klasa izvedena iz apstraktne klase Reader. Cita sa standardnog ulaza.
class ConsoleReader : protected Reader {
public:
    ConsoleReader();
    ~ConsoleReader() override = default;

    std::string readNewLine() override;
    std::string readMultiLine() override;
};


#endif //CLI_CONSOLEREADER_H