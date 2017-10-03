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

enum TokenType {Integer, Plus, eof};

struct Type {
    TokenType t;
    std::string toString() {
        std::string ans;
        switch(t) {
            case Integer:
                ans = "INTEGER";
                break;
            case Plus:
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


class Token {
    // token type: INTEGER, PLUS, or EOF
    Type _type;
    // token value: 0, 1, 2. 3, 4, 5, 6, 7, 8, 9, '+', or None
    char    _value;
public:
    // Constructors
    Token();
    Token(TokenType t, char value);
    
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
    char getValue();
};

#endif /* Token_hpp */

