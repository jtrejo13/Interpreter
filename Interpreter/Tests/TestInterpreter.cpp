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
    Token myToken(Integer, "10");
    ASSERT_EQ(myToken.toString(), "Token(INTEGER, 10)");
}

TEST(test_token, token_construct_2) {
    Token myToken(Plus, "+");
    ASSERT_EQ(myToken.toString(), "Token(PLUS, +)");
}

TEST(test_token, token_construct_3) {
    Token myToken(eof, "EOF");
    ASSERT_EQ(myToken.toString(), "Token(EOF, None)");
}

///////////////////////////////
// MARK: Interpreter_NEXT_TOKEN
///////////////////////////////

TEST(test_interp, interp_next_token_1) {
    Interpreter myInterp("2");
    ASSERT_EQ(myInterp.getNextToken().toString(), "Token(INTEGER, 2)");
}

TEST(test_interp, interp_next_token_2) {
    Interpreter myInterp("23424");
    ASSERT_EQ(myInterp.getNextToken().toString(), "Token(INTEGER, 23424)");
}

TEST(test_interp, interp_next_token_3) {
    Interpreter myInterp("    424+");
    ASSERT_EQ(myInterp.getNextToken().toString(), "Token(INTEGER, 424)");
}

////////////////////////////
// MARK: Interpreter_EXPRESS
////////////////////////////

TEST(test_interp, interp_express_sum_1) {
    Interpreter myInterp("1 + 1");
    ASSERT_EQ(myInterp.eval(), 2);
}

TEST(test_interp, interp_express_sum_2) {
    Interpreter myInterp("9 + 19");
    ASSERT_EQ(myInterp.eval(), 28);
}

TEST(test_interp, interp_express_sum_3) {
    Interpreter myInterp("0  +  0");
    ASSERT_EQ(myInterp.eval(), 0);
}

//TEST(test_interp, interp_express_sub_1) {
//    Interpreter myInterp("2 - 1");
//    ASSERT_EQ(myInterp.eval(), 1);
//}
//
//TEST(test_interp, interp_express_sub_2) {
//    Interpreter myInterp("15 - 5");
//    ASSERT_EQ(myInterp.eval(), 10);
//}

TEST(test_interp, interp_express_exept_4) {
    Interpreter myInterp("++0");
    ASSERT_THROW(myInterp.eval(), std::invalid_argument);
}

