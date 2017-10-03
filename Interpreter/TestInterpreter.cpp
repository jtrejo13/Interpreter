//
//  TestInterpreter.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/1/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include <cstdio>
#include "gtest/gtest.h"
#include "Token.hpp"
#include "Interpreter.hpp"

/////////////////////////
// MARK: Token
/////////////////////////

TEST(test_token, token_construct_0) {
    Token myToken = Token();
    ASSERT_EQ(myToken.toString(), "Token(EOF, None)");
}

TEST(test_token, token_construct_1) {
    Token myToken(Integer, '9');
    ASSERT_EQ(myToken.toString(), "Token(INTEGER, 9)");
}

TEST(test_token, token_construct_2) {
    Token myToken(Plus, '+');
    ASSERT_EQ(myToken.toString(), "Token(PLUS, +)");
}

TEST(test_token, token_construct_3) {
    Token myToken(eof, EOF);
    ASSERT_EQ(myToken.toString(), "Token(EOF, None)");
}

/////////////////////////
// MARK: Interpreter
/////////////////////////

TEST(test_interp, interp_express_1) {
    Interpreter myInterp("1+3");
    ASSERT_EQ(myInterp.eval(), 4);
}

TEST(test_interp, interp_express_2) {
    Interpreter myInterp("9+9");
    ASSERT_EQ(myInterp.eval(), 18);
}
