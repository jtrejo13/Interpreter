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

/////////////////////////
// MARK: Constructors
/////////////////////////

TEST(test_token, token_construct_1) {
    Token<int> myToken(integer, 10);
    ASSERT_EQ(myToken.toString(), "Token(INTEGER, 10)");
}

TEST(test_token, token_construct_2) {
    Token<char> myToken(plus, '+');
    ASSERT_EQ(myToken.toString(), "Token(PLUS, +)");
}

TEST(test_token, token_construct_3) {
    Token<char> myToken(eof, std::char_traits<char>::eof());
    ASSERT_EQ(myToken.toString(), "Token(EOF, None)");
}


/////////////////////////
// MARK: Member Functions
/////////////////////////

