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
    _type = eof;
    _value = "None";
}

Token::Token(TokenType T, std::string value) {
    _type = T;
    _value = value;
}

std::string Token::toString() {
    std::ostringstream out;
    out << "Token(";
    out << typeToString(_type);
    if (_type != eof) {
        out << ", " << _value << ")";
    } else {
        out << ", None)";  // Handle eof
    }
    return out.str();
}

TokenType Token::getType() {
    return _type;
}

std::string Token::getValue() {
    return _value;
}

std::string typeToString(TokenType T) {
    std::string ans;
    switch(T) {
        case Integer:
            ans = "INTEGER";
            break;
        case Plus:
        case Minus:
        case Mul:
        case Div:
            ans = "BINARY_OP";
            break;
        case LParen:
        case RParen:
            ans = "PAREN";
            break;
        case eof:
            ans = "EOF";
            break;
        default:
            ans = "UNDEF";
            break;
    }
    return ans;
}

#endif

