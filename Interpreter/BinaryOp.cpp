//
//  BinaryOp.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include "BinaryOp.hpp"

BinaryOp::BinaryOp() {
    //nothing to do
}

BinaryOp::BinaryOp(Num* left, Token op, Num* right) : Node(left, op, right) {
    _left  = left;
    _op    = op;
    _right = right;
}


