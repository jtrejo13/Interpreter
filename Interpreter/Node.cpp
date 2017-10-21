//
//  Node.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include "Node.hpp"

Node::Node() {
    _left = nullptr;
    _token = Token();
    _right = nullptr;
}

Node::Node(Token t) : _token(t)
{
    _left = nullptr;
    _right = nullptr;
}

Node::Node(Node* left, Token t, Node* right) : _token(t)
{
    _left = left;
    _right = right;
}

Node* Node::left() {
    return _left;
}

Node* Node::right() {
    return _right;
}

std::string Node::getType() {
    return typeToString(_token.getType());
}

Token Node::getToken() {
    return _token;
}

