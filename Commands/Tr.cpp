#include "Tr.h"

Tr::Tr(const Token &textSource, const Token &what, const Token &with, bool pipe) : TextCommand(textSource, pipe) {
    handle = "tr";
}

void Tr::execute() {

}

std::string Tr::getHandle() {
    return handle;
}
