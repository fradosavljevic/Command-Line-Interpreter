#ifndef CLI_STREAMREADER_H
#define CLI_STREAMREADER_H
#include "Reader.h"


class StreamReader : public Reader {
public:
    StreamReader(std::istream* stream);

    std::string readNewLine() override;

    std::string readMultiLine() override;
};


#endif //CLI_STREAMREADER_H