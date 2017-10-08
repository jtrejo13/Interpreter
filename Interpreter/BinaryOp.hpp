//
//  BinaryOp.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef BinaryOp_hpp
#define BinaryOp_hpp

#include <stdio.h>
#include "Node.hpp"
#include "Token.hpp"
#include "Num.hpp"

class BinaryOp : public Node {
    Num* _left;
    Num* _right;
    Token _op;
    
public:
    BinaryOp();
    BinaryOp(Num* left, Token op, Num* right);
};

#endif /* BinaryOp_hpp */
