//
//  Parser.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser(Scanner* s) {
    _scanner = s;
    _currentToken = _scanner->getNextToken();
}

Node* Parser::parse() {
    return expr();
}

Node* Parser::expr() {
    Node* node = term();
    
    while(_currentToken.getTokenType() == Plus || _currentToken.getTokenType() == Minus) {
        Token token = _currentToken;
        if (token.getValue() == "+") {
            eat(Plus);
        } else if (token.getValue() == "-") {
            eat(Minus);
        }
        node = new BinaryOp(reinterpret_cast<Num*>(node), token, reinterpret_cast<Num*>(term()));
    }
    return node;
}

Node* Parser::term() {
    Node* node = factor();

    while(_currentToken.getTokenType() == Mul || _currentToken.getTokenType() == Div) {
        Token token = _currentToken;
        if (token.getValue() == "*") {
            eat(Mul);
        } else if (token.getValue() == "/") {
            eat(Div);
        }
        node = new BinaryOp(reinterpret_cast<Num*>(node), token, reinterpret_cast<Num*>(factor()));
    }
    return node;
}

Node* Parser::factor() {
    Token token = _currentToken;
    if (token.getTokenType() == Integer) {
        eat(Integer);
        return new Num(token);
    } else if (token.getValue() == "(") {
        eat(LParen);
        Node* node = expr();
        eat(RParen);
        return node;
    }
    raiseError();
    return new Num();
}

void Parser::eat(TokenType T) {
    if (T == _currentToken.getTokenType()) {
        _currentToken = _scanner->getNextToken();
    } else {
        raiseError();
    }
}

void Parser::raiseError() {
    throw std::invalid_argument("Invalid syntax.");
}
