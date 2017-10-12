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
#include "Parser.hpp"
#include "Node.hpp"

class Interpreter {
    
    Parser* _parser;
    
    int visit(Node* node);
    
    /**
     *
     *
     *
     */
    void raiseError();
    
public:
    // Constructors
    /**
     *
     */
    Interpreter(Parser* parser);
    
    int interpret();
    
};

#endif /* Interpreter_hpp */

