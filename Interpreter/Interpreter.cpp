//
//  Interpreter.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Interpreter_cpp
#define Interpreter_cpp

#include "Interpreter.hpp"

Interpreter::Interpreter(std::string text) {
    _text = text;
    _pos = 0;
}

Token Interpreter::getNextToken() {
    if (_pos > _text.size() - 1) {
        return Token(eof, "EOF");
    }
    
    std::string currentChar = _text.substr(_pos, 1);

    if (isInteger(currentChar)) {
        _pos += 1;
        return Token(Integer, currentChar);
    } else if (currentChar[0] == '+') {
        _pos += 1;
        return Token(Plus, currentChar);
    } else {
        error();
        return Token();
    }
    return Token();
}

void Interpreter::eat(TokenType t) {
    if (_currentToken.getTokenType() == t) {
        _currentToken = getNextToken();
    } else {
        error();
    }
}

int Interpreter::eval() {
    _currentToken = getNextToken();
    
    int left = stringToInteger(_currentToken.getValue());
    eat(Integer);

    eat(Plus);

    int right = stringToInteger(_currentToken.getValue());
    eat(Integer);

    return left + right;
    return 0;
}

void Interpreter::error() {
    throw std::invalid_argument("Error parsing input");
}

#endif

