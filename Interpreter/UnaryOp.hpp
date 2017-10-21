//
//  UnaryOp.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/21/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef UnaryOp_hpp
#define UnaryOp_hpp

#include <stdio.h>
#include "Node.hpp"

class UnaryOp : public Node {
    
public:
    using Node::Node;
    std::string getType() {
        return "UNARY_OP";
    }
};

#endif /* UnaryOp_hpp */
