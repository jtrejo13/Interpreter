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
    Node* _right;
    Token _token;
public:
    Node();
    Node(Token t);
    Node(Node* left, Token t, Node* right);
};
#endif /* Node_hpp */
