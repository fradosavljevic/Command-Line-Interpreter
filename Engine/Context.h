#ifndef CLI_CONTEXT_H
#define CLI_CONTEXT_H
#include <istream>

class Context {
public:
    Context() : inputStream(nullptr), outputStream(nullptr) {}
    Context(std::istream* input, std::ostream* output) : inputStream(input), outputStream(output) {};
    ~Context() = default;
    std::istream* inputStream;
    std::ostream* outputStream;
};


#endif