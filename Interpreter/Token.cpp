//
//  Token.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef __TOKEN_CPP
#define __TOKEN_CPP

#include "Token.hpp"

Token::Token() {
    _type = {eof};
    _value = -1;
}

Token::Token(TokenType t, char value) {
    _type = {t};
    _value = value;
}

std::string Token::toString() {
    std::ostringstream out;
    out << "Token(";
    out << _type.toString();
    if (_type.t != eof) {
        out << ", " << _value << ")";
    } else {
        out << ", None)";  // Handle eof
    }
    return out.str();
}

TokenType Token::getTokenType() {
    return _type.t;
}

char Token::getValue() {
    return _value;
}

#endif

