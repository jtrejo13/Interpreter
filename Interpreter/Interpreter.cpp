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

Interpreter::Interpreter(Scanner* scanner) {
    _scanner = scanner;
    _currentToken = _scanner->getNextToken();
}

void Interpreter::eat(TokenType T) {
    if (_currentToken.getTokenType() == T) {
        _currentToken = _scanner->getNextToken();
    } else {
        raiseError();
    }
}

int Interpreter::factor() {
    Token token = _currentToken;
    if (token.getValue() == "(") {
        eat(LParen);
        int result = expr();
        eat(RParen);
        return result;
    } else if (token.getTokenType() == Integer) {
        eat(Integer);
        return stringToInteger(token.getValue());
    }
    raiseError();
    return 0;
}

int Interpreter::term() {
    int result = factor();

    while (_currentToken.getTokenType() == Mul || _currentToken.getTokenType() == Div) {
        Token op = _currentToken;
        if (op.getValue() == "*") {
            eat(Mul);
            result *= factor();
        } else if (op.getValue() == "/"){
            eat(Div);
            result /= factor();
        }
    }
    return result;
}


int Interpreter::expr() {
    int result = term();
   
    while ( _currentToken.getTokenType() == Plus || _currentToken.getTokenType() == Minus) {
        Token op = _currentToken;
        if (op.getValue() == "+") {
            eat(Plus);
            result += term();
        } else if (op.getValue() == "-") {
            eat(Minus);
            result -= term();
        }
    }
    return result;
}

void Interpreter::raiseError() {
    throw std::invalid_argument("Error parsing input");
}

#endif

