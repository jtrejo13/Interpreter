//
//  Parser.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include "BinaryOp.hpp"
#include "Num.hpp"
#include "Token.hpp"
#include "Scanner.hpp"

class Parser {
    Scanner* _scanner;
    Token _currentToken;
    
public:
    Parser(Scanner* s);
    
    Node* parse();
    Node* expr();
    Node* term();
    Node* factor();
    void eat(TokenType T);
    void raiseError();
};
#endif /* Parser_hpp */
