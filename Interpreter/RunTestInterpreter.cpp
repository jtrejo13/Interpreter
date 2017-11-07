//
//  main.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Interpreter.hpp"
#include "Scanner.hpp"
#include "Parser.hpp"
#include "gtest/gtest.h"

int main(int argc, char * argv[]) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

    std::string txt;
    while(true) {
        std::cout << ">> ";
        std::getline(std::cin, txt);
        Scanner* s = new Scanner(txt);
        Parser*  p = new Parser(s);
        Interpreter in = Interpreter(p);
        std::cout << ">> " << in.interpret() << std::endl;
    }
}

