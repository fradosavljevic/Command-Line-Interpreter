#ifndef CLI_CONTEXT_H
#define CLI_CONTEXT_H
#include <istream>

// Sluzi da dostavi neophodne informacije klasi InterpreterEngine prilikom izvrsavanja batch komande.
class Context {
public:
    Context() : inputStream(nullptr), outputStream(nullptr) {}
    Context(std::istream* input, std::ostream* output) : inputStream(input), outputStream(output) {};
    ~Context() = default;
    std::istream* inputStream;
    std::ostream* outputStream;
};


#endif