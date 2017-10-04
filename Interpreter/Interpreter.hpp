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
#include <sstream>
#include <string>
#include "Token.hpp"
#include "strhelper.hpp"

class Interpreter {
    // client string input, e.g. "3+5"
    std::stringstream _in;

    Token       _currentToken;

public:
    // Constructors
//    Interpreter();
//    Interpreter(std::istream& in);
    Interpreter(std::string text);
    
    void skipWhitespace();
    std::string getIntegerStr();
    Token getNextToken();
    void eat(TokenType t);
    int eval();
    void error();
};

#endif /* Interpreter_hpp */

