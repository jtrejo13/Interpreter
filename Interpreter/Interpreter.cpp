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

Interpreter::Interpreter(Parser* parser) {
    _parser = parser;
}

int Interpreter::interpret() {
    Node* tree = _parser->parse();
    return visit(tree);
}

int Interpreter::visit(Node* node) {
    if (node->getType() == "INTEGER") {
        return visitNum(node);
    } else if (node->getType() == "BINARY_OP") {
        return visitBiOp(node);
    } else if (node->getType() == "UNARY_OP") {
        return visitUnOp(node);
    }
    throwError();
    return 0;
}

int Interpreter::visitBiOp(Node* node) {
    Token t = node->getToken();
    if (t.getType() == Plus) {
        return visit(node->left()) + visit(node->right());
    } else if (t.getType() == Minus) {
        return visit(node->left()) - visit(node->right());
    } else if (t.getType() == Mul) {
        return visit(node->left()) * visit(node->right());
    } else if (t.getType() == Div) {
        return visit(node->left()) / visit(node->right());
    }
    throwError();
    return 0;
}

int Interpreter::visitUnOp(Node* node) {
    Token t = node->getToken();
    if (t.getType() == Plus) {
        return visit(node->right());
    } else if (t.getType() == Minus) {
        return -1 * visit(node->right());
    }
    throwError();
    return 0;
}

int Interpreter::visitNum(Node* node) {
    Token t = node->getToken();
    return stringToInteger(t.getValue());
}

void Interpreter::throwError() {
    throw std::invalid_argument("Error parsing input");
}

#endif

