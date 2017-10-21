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
        node = new BinaryOp(node, token, term());
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
        node = new BinaryOp(node, token, factor());
    }
    return node;
}

Node* Parser::factor() {
    Token token = _currentToken;
    if (token.getType() == Plus) {
        eat(Plus);
        return new UnaryOp(nullptr, token, factor());
    } else if (token.getType() == Minus) {
        eat(Minus);
        return new UnaryOp(nullptr, token, factor());
    } else
    if (token.getType() == Integer) {
        eat(Integer);
        return new Num(token);
    } else if (token.getValue() == "(") {
        eat(LParen);
        Node* node = expr();
        eat(RParen);
        return node;
    }
    throwError();
    return new Node();
}

void Parser::eat(TokenType T) {
    if (T == _currentToken.getType()) {
        _currentToken = _scanner->getNextToken();
    } else {
        throwError();
    }
}

void Parser::throwError() {
    throw std::invalid_argument("Invalid syntax.");
}

void printTree(Node* p, int indent) {
    if(p != NULL) {
        if(p->right()) {
            printTree(p->right(), indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right()) {
            std::cout<<" /\n" << std::setw(indent) << ' ';
        }
        std::cout<< p->getToken().toString() << "\n ";
        if(p->left()) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printTree(p->left(), indent+4);
        }
    }
}
