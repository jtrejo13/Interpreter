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
#include "Scanner.hpp"
#include "strhelper.hpp"

class Interpreter {
    /**
     * @brief client string input, e.g. "3+5"
     */
    std::stringstream _in;
    
    /**
     *
     */
    Token   _currentToken;
    
    /**
     *
     */
    Scanner* _scanner;

public:
    // Constructors
    /**
     *
     */
    Interpreter(Scanner* scanner);
    
    /**
     *
     *
     *
     */
    void eat(TokenType t);
    
    /**
     *
     *
     *
     */
    int factor();
    
    /**
     *
     *
     *
     */
    int term();
    
    /**
     * @brief Arithmetic expression parser / interpreter.
     *
     * calc> 7 + 3 * (10 / (12 / (3 + 1) - 1))
     * 22
     *
     * expr   : term ((PLUS | MINUS) term)*
     * term   : factor ((MUL | DIV) factor)*
     * factor : INTEGER | LPAREN expr RPAREN
     */
    int expr();
    
    /**
     *
     *
     *
     */
    void raiseError();
};

#endif /* Interpreter_hpp */

