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
    _in = std::stringstream(text);
}

void Interpreter::skipWhitespace() {
    while (_in.peek() == ' ') {
        _in.ignore();
    }
}

std::string Interpreter::getIntegerStr() {
    std::string res = "";
    while(!_in.eof() && isdigit(_in.peek())){
        res += _in.get();
    }
    return res;
}

Token Interpreter::getNextToken() {
    
    while (!_in.eof()) {
        if (_in.peek() == ' ') {
            skipWhitespace();
        }
            
        if (isdigit(_in.peek())) {
            return Token(Integer, getIntegerStr());
        }
        
        if (_in.peek() == '+') {
            return Token(Plus, std::string(1, _in.get()));
        }
        
        if (_in.peek() == '-') {
            return Token(Minus, std::string(1, _in.get()));
        }
        
        if (_in.peek() == '*') {
            return Token(Mul, std::string(1, _in.get()));
        }
        
        if (_in.peek() == '/') {
            return Token(Div, std::string(1, _in.get()));
        }
    }
    return Token(eof, "EOF");
}

void Interpreter::eat(TokenType T) {
    if (_currentToken.getTokenType() == T) {
        _currentToken = getNextToken();
    } else {
        error();
    }
}

int Interpreter::factor() {
    Token token = _currentToken;
    eat(Integer);
    return stringToInteger(token.getValue());
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
    _currentToken = getNextToken();
    
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

void Interpreter::error() {
    throw std::invalid_argument("Error parsing input");
}

#endif

