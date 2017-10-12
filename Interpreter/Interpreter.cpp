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

Interpreter::Interpreter(Parser* parser) {
    _parser = parser;
}

int Interpreter::interpret() {
    Node* tree = _parser->parse();
    return visit(tree);
}

int Interpreter::visit(Node* node) {
    if (node->getType() == "INTEGER") {
        
    } else if (node->getType() == "BINARY_OP") {
        
    }
    return 0;
}

void Interpreter::raiseError() {
    throw std::invalid_argument("Error parsing input");
}

#endif

