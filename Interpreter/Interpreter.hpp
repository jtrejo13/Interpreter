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
    Token       _currentToken;

public:
    // Constructors
    Interpreter(std::string text);
    
    Token getNextToken();
    void eat(TokenType t);
    int eval();
    void error();
};

#endif /* Interpreter_hpp */

