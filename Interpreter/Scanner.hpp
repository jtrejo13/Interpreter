//
//  Scanner.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/8/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef Scanner_hpp
#define Scanner_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <istream>
#include "Token.hpp"

class Scanner {
    std::stringstream _in;
public:
    
    // Constructors
    Scanner(std::string input);
    
    /**
     *
     *
     *
     */
    Token getNextToken();
    
    /**
     *
     *
     *
     */
    void skipWhitespace();
    
    /**
     *
     *
     *
     */
    std::string getIntegerStr();
    
    /**
     *
     *
     *
     */
    void raiseError();
    
};

#endif /* Scanner_hpp */
