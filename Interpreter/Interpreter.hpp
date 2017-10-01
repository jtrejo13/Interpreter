//
//  Interpreter.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Interpreter_hpp
#define Interpreter_hpp

#include <ctype.h>
#include <iostream>
#include <string>
#include "Token.hpp"

class Interpreter {
    // client string input, e.g. "3+5"
    std::string _text;
    // self.pos is an index into _text
    int         _pos;
    void*       _currentToken;

public:
    // Constructors
    Interpreter(std::string text);
    
    template <typename T>
    Token<T>* getNextToken();
    template <typename T>
    void eat(TokenType t);
    int expression();
    void error();
};


#include "Interpreter.cpp"

#endif /* Interpreter_hpp */

