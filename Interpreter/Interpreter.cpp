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

void Interpreter::skipWhitespace() {
    while (_text[_pos] == ' ') {
        ++_pos;
    }
}

Token Interpreter::getNextToken() {
    std::string currentChar = _text.substr(_pos, 1);

    if (isInteger(currentChar)) {
        _pos += 1;
        return Token(Integer, currentChar);
    } else if (currentChar[0] == '+') {
        _pos += 1;
        return Token(Plus, currentChar);
    } else {
        error();
    }
    return Token(eof, "EOF");
}

void Interpreter::eat(TokenType t) {
    _currentToken = getNextToken();
    if (_currentToken.getTokenType() != t) {
        error();
    }
}

int Interpreter::eval() {
    eat(Integer);
    int left = stringToInteger(_currentToken.getValue());
    
    eat(Plus);

    eat(Integer);
    int right = stringToInteger(_currentToken.getValue());

    return left + right;
    return 0;
}

void Interpreter::error() {
    throw std::invalid_argument("Error parsing input");
}

#endif

