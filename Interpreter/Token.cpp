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

template <typename T>
Token<T>::Token(TokenType t, T value) {
    _type = {t};
    _value = value;
}

template <typename T>
std::string Token<T>::toString() {
    std::ostringstream out;
    out << "Token(";
    out << _type.toString();
    if (_value != EOF) {
        out << ", " << _value << ")";
    } else {
        out << ", None)";  // Handle eof
    }
    return out.str();
}

template <typename T>
TokenType Token<T>::getTokenType() {
    return _type.t;
}

#endif

