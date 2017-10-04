//
//  TestStringHelper.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/4/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

/*
template <typename FI, typename T>
void my_fill(FI b, FI e, T n) {
    while (b != e) {
        *b = n;
        ++b;
    }
}
 
template <typename FI, typename T>
void my_iota(FI b, FI e, T n) {
     T i = n;
     while (b != e) {
         *b = i;
         ++b;
         ++i;
     }
}

template <typename FI, typename T, typename BF>
 T my_accumulate(FI b, FI e, const T& s, BF f) {
     while(b != e) {
         s = f(s, *b);
         ++b;
     }
     return s;
 }
 
 
 */

#include <stdio.h>
#include <string>
#include "gtest/gtest.h"
#include "strhelper.hpp"

TEST(test_strhelper, str_to_int_1) {
    std::string numstr = "1";
    ASSERT_TRUE(isInteger(numstr));
    ASSERT_EQ(stringToInteger(numstr), 1);
}

TEST(test_strhelper, str_to_int_pos) {
    std::string numstr = "+10";
    ASSERT_TRUE(isInteger(numstr));
    ASSERT_EQ(stringToInteger(numstr), 10);
}

TEST(test_strhelper, str_to_int_neg) {
    std::string numstr = "-153";
    ASSERT_TRUE(isInteger(numstr));
    ASSERT_EQ(stringToInteger(numstr), -153);
}

TEST(test_strhelper, str_to_int_throw) {
    std::string str = "notAnInt";
    ASSERT_FALSE(isInteger(str));
    ASSERT_THROW(stringToInteger(str), std::invalid_argument);
}

TEST(test_strhelper, int_to_str_1) {
    int i = 130;
    ASSERT_EQ(integerToString(i), "130");
}
