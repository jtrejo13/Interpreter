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
    
    while(_currentToken.getType() == Plus || _currentToken.getType() == Minus) {
        Token token = _currentToken;
        if (token.getValue() == "+") {
            eat(Plus);
        } else if (token.getValue() == "-") {
            eat(Minus);
        }
        node = new Node(node, token, term());
    }
    return node;
}

Node* Parser::term() {
    Node* node = factor();

    while(_currentToken.getType() == Mul || _currentToken.getType() == Div) {
        Token token = _currentToken;
        if (token.getValue() == "*") {
            eat(Mul);
        } else if (token.getValue() == "/") {
            eat(Div);
        }
        node = new Node(node, token, factor());
    }
    return node;
}

Node* Parser::factor() {
    Token token = _currentToken;
    if (token.getType() == Integer) {
        eat(Integer);
        return new Node(token);
    } else if (token.getValue() == "(") {
        eat(LParen);
        Node* node = expr();
        eat(RParen);
        return node;
    }
    raiseError();
    return new Node();
}

void Parser::eat(TokenType T) {
    if (T == _currentToken.getType()) {
        _currentToken = _scanner->getNextToken();
    } else {
        raiseError();
    }
}

void Parser::raiseError() {
    throw std::invalid_argument("Invalid syntax.");
}
