//
//  Token.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <sstream>
#include <string>

template <typename T>
class Token {
    T _value;
public:
    // Constructors
    Token();
    Token(T value);
    
    /* *
     * @brief String representation of the class instance.
     * @return token as a std::string
     * Examples:
     * Token(INTEGER, 3)
     * Token(PLUS '+')
     */
    std::string toString();
};

#include "Token.cpp"

#endif /* Token_hpp */

