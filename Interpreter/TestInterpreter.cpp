//
//  TestInterpreter.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include "gtest/gtest.h"
#include "Token.hpp"

/////////////////////////
// MARK: Constructors
/////////////////////////

TEST(test_token, token_construct_1) {
    Token<double> myToken(10.5);
    ASSERT_EQ(myToken.toString(), "Token(d, 10.5)");
}

TEST(test_token, token_construct_2) {
    Token<int> myToken;
    ASSERT_EQ(myToken.toString(), "Token(i, 0)");
}

/////////////////////////
// MARK: Member Functions
/////////////////////////

