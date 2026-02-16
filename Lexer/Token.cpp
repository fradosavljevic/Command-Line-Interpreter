#include "Token.h"
using namespace std;

Token::Token() {
    this->type = TokenType::NIL;
    this->value = string();
}

Token::Token(const TokenType type, const string &value) {
    this->type = type;
    this->value = value;
}

string Token::getValue() const {
    return value;
}

TokenType Token::getType() const {
    return type;
}
