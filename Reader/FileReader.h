#ifndef CLI_FILEREADER_H
#define CLI_FILEREADER_H
#include "Reader.h"
#include <fstream>

// Klasa izvedena od apstraktne klase Reader. Cita sadrzaj fajla koji joj se prosledi.
class FileReader : public Reader {
public:
    explicit FileReader(const std::string& path);

    std::string readNewLine() override;
    std::string readMultiLine() override;
private:
    std::ifstream file;
};


#endif //CLI_FILEREADER_H