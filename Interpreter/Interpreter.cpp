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

template <typename T>
Token<T>* Interpreter::getNextToken() {
    if (_pos > _text.size() - 1) {
        return new Token<char>(eof, EOF);
    }
    
    char currentChar = _text[_pos];
    
    if (std::isdigit(currentChar)) {
        _pos += 1;
        return new Token<int>(Integer, currentChar - '0');
    }
    
    if (currentChar == '+') {
        _pos += 1;
        return new Token<char>(Plus, currentChar);
    }
    
    error();
}

template <typename T>
void Interpreter::eat(TokenType t) {
    Token<T>* token = static_cast<Token<T>*>(_currentToken);
    if (token->getTokenType() == t) {
        _currentToken = getNextToken<T>();
    } else {
        error();
    }
}

void Interpreter::error() {
    throw std::invalid_argument("Error parsing input");
}

#endif

