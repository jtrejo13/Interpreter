//
//  Node.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Token.hpp"

class Node {
    Node* _left;
    Token _token;
    Node* _right;
public:
    Node();
    Node(Token t);
    Node(Node* left, Token t, Node* right);
    std::string getType();
};
#endif /* Node_hpp */
