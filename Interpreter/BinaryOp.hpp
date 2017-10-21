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
    
public:
    using Node::Node;
    std::string getType() {
        return "BINARY_OP";
    }
};

#endif /* BinaryOp_hpp */
