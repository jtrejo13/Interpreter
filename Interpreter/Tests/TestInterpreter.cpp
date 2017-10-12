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
    ASSERT_EQ(myToken.toString(), "Token(BINARY_OP, +)");
}

TEST(test_token, token_construct_3) {
    Token myToken(Minus, "-");
    ASSERT_EQ(myToken.toString(), "Token(BINARY_OP, -)");
}

TEST(test_token, token_construct_4) {
    Token myToken(eof, "EOF");
    ASSERT_EQ(myToken.toString(), "Token(EOF, None)");
}


///////////////////////////////
// MARK: Scanner
///////////////////////////////

TEST(test_interp, interp_next_token_1) {
    Scanner* scanner = new Scanner("2");
    ASSERT_EQ(scanner->getNextToken().toString(), "Token(INTEGER, 2)");
}

TEST(test_interp, interp_next_token_2) {
    Scanner* scanner = new Scanner("23424");
    ASSERT_EQ(scanner->getNextToken().toString(), "Token(INTEGER, 23424)");
}

TEST(test_interp, interp_next_token_3) {
    Scanner* scanner = new Scanner("    424+");
    ASSERT_EQ(scanner->getNextToken().toString(), "Token(INTEGER, 424)");
}

//////////////////////////////
// MARK: Interpreter_BinaryOp
//////////////////////////////

//TEST(test_interp, interp_express_sum_1) {
//    Scanner* s = new Scanner("1 + 1");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 2);
//}
//
//TEST(test_interp, interp_express_sum_2) {
//    Scanner* s = new Scanner("9 + 19");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 28);
//}
//
//TEST(test_interp, interp_express_sum_3) {
//    Scanner* s = new Scanner("0  +  0");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 0);
//}
//
//TEST(test_interp, interp_express_sub_1) {
//    Scanner* s = new Scanner("2 - 1");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 1);
//}
//
//TEST(test_interp, interp_express_sub_2) {
//    Scanner* s = new Scanner("15 - 5");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 10);
//}
//
//TEST(test_interp, interp_express_mult_1) {
//    Scanner* s = new Scanner("2 * 14");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 28);
//}
//
//TEST(test_interp, interp_express_mult_2) {
//    Scanner* s = new Scanner("15 * 5");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 75);
//}
//
//TEST(test_interp, interp_express_div_1) {
//    Scanner* s = new Scanner("28 / 14");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 2);
//}
//
//TEST(test_interp, interp_express_div_2) {
//    Scanner* s = new Scanner("15 / 5");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 3);
//}

//////////////////////////////
// MARK: Interpreter_OperationStr
//////////////////////////////

//TEST(test_interp, interp_express_short_1) {
//    Scanner* s = new Scanner("3");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 3);
//}
//
//TEST(test_interp, interp_express_long_1) {
//    Scanner* s = new Scanner("15 + 5 - 6 + 11 - 13 - 2");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 10);
//}
//
//TEST(test_interp, interp_express_long_2) {
//    Scanner* s = new Scanner("10 * 4  * 2 * 3 / 8");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 30);
//}
//
//TEST(test_interp, interp_express_mix_1) {
//    Scanner* s = new Scanner("14 + 2 * 3 - 6 / 2");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 17);
//}
//
//TEST(test_interp, interp_express_paren_1) {
//    Scanner* s = new Scanner("(1 + 1)");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 2);
//}
//
//TEST(test_interp, interp_express_paren_2) {
//    Scanner* s = new Scanner("7 + 3 * (10 / (12 / (3 + 1) - 1))");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 22);
//}
//
//TEST(test_interp, interp_express_paren_3) {
//    Scanner* s = new Scanner("7 + 3 * (10 / (12 / (3 + 1) - 1)) / (2 + 3) - 5 - 3 + (8)");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 10);
//}
//
//TEST(test_interp, interp_express_paren_4) {
//    Scanner* s = new Scanner("7 + (((3 + 2)))");
//    Interpreter myInterp(s);
//    ASSERT_EQ(myInterp.expr(), 12);
//}
//
//TEST(test_interp, interp_express_exept_4) {
//    Scanner* s = new Scanner("++0");
//    Interpreter myInterp(s);
//    ASSERT_THROW(myInterp.expr(), std::invalid_argument);
//}

