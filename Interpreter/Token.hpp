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

enum TokenType {Integer, Plus, Minus, Mul, Div, eof};

struct Type {
    TokenType t;
    std::string toString() {
        std::string ans;
        switch(t) {
            case Integer:
                ans = "INTEGER";
                break;
            case Plus:
            case Minus:
            case Mul:
            case Div:
                ans = "BINARY_OP";
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


class Token {
    /* *
     * @brief token type: INTEGER, PLUS, MINUS, MUL, DIV or EOF
     */
    Type _type;
    
    /* *
     * @brief token value: 0, 1, 2. 3, 4, 5, 6, 7, 8, 9, '+', '-', or None
     */
    std::string _value;
public:
    // Constructors
    Token();
    Token(TokenType t, std::string value);
    
    /* *
     * @brief String representation of the class instance.
     * @return token as a std::string
     * Examples:
     * Token(INTEGER, 3)
     * Token(PLUS '+')
     */
    std::string toString();
    
    /* *
     * @brief
     * @return
     */
    TokenType getTokenType();
    
    /* *
     * @brief
     * @return
     */
    std::string getValue();
};

#endif /* Token_hpp */

