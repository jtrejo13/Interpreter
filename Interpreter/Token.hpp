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

enum type {integer, plus, eof};

struct Type {
    type t;
    std::string toString() {
        std::string ans;
        switch(t) {
            case integer:
                ans = "INTEGER";
                break;
            case plus:
                ans = "PLUS";
                break;
            case eof:
                ans = "EOF";
                break;
            default:
                ans = "UNDEF";
                break;
        }
        return ans;
    }
};

template <typename T>
class Token {
    // token type: INTEGER, PLUS, or EOF
    Type _type;
    // token value: 0, 1, 2. 3, 4, 5, 6, 7, 8, 9, '+', or None
    T    _value;
public:
    // Constructors
    Token(type t, T value);
    
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

