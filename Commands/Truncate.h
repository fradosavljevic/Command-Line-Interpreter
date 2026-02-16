#ifndef CLI_TRUNCATE_H
#define CLI_TRUNCATE_H
#include "SingleFileCommand.h"


class Truncate : public SingleFileCommand {
public:
    explicit Truncate(const Token& filename, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_TRUNCATE_H