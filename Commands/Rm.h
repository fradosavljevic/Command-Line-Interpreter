#ifndef CLI_RM_H
#define CLI_RM_H
#include "SingleFileCommand.h"


class Rm : public SingleFileCommand {
public:
    explicit Rm(const Token& filename, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_RM_H