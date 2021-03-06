//
//  Num.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Num_hpp
#define Num_hpp

#include <stdio.h>
#include "Node.hpp"
#include "Token.hpp"

class Num : public Node {

public:
    using Node::Node;
    std::string getType() {
        return "INTEGER";
    }
};

#endif /* Num_hpp */
