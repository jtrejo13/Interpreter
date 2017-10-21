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
#include <map>

enum TokenType {Integer, Plus, Minus, Mul, Div, LParen, RParen, eof};
const std::map <int, std::string> TokenTypeNames {
    { Integer , "Integer" },
    { Plus    , "Plus" },
    { Minus   , "Minus" },
    { Mul     , "Mul" },
    { Div     , "Div" },
    { LParen  , "LParen" },
    { RParen  , "RParen" },
    { eof     , "eof" }
};

class Token {
    /* *
     * @brief token type: INTEGER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, or EOF
     */
    TokenType _type;
    
    /* *
     * @brief token value: 0, 1, 2. 3, 4, 5, 6, 7, 8, 9, '+', '-',
     * '*', '/', '(', ')', or None
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
     * Token(BINARY_OP '+')
     */
    std::string toString();
    
    /* *
     * @brief
     * @return
     */
    TokenType getType();
    
    /* *
     * @brief
     * @return
     */
    std::string getValue();
};

std::string typeToString(TokenType T);

#endif /* Token_hpp */

