//
//  Token.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef __TOKEN_CPP
#define __TOKEN_CPP

#include "Token.hpp"

template <typename T>
Token<T>::Token() {
    _value = T();
}

template <typename T>
Token<T>::Token(T value) {
    _value = value;
}

template <typename T>
std::string Token<T>::toString()
{
    std::ostringstream out;
    out << "Token(";
    out << typeid(T).name();
    out << ", " << _value << ")";
    return out.str();
}

#endif

