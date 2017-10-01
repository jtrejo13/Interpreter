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

//void Interpreter::getNextToken() {
//    if (_pos > _text.size() - 1) {
//
//    }
//}

void Interpreter::error() {
    throw std::invalid_argument("Error parsing input");
}

#endif

