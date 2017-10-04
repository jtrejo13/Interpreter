//
//  strhelper.cpp
//  Interpreter
//
//  Created by Juan Trejo on 10/4/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include "strhelper.hpp"

bool canConvertToInteger(const std::string& s, long& i) {
    if(s.empty() || (!isdigit(s[0]) && s[0] != '-' && s[0] != '+')) return false;
    
    const char* start = s.c_str();
    char* end;
    i = std::strtol(start, &end, 10);
    return *end == 0;
}

bool isInteger(const std::string& s) {
    long i;
    return canConvertToInteger(s, i);
}

int stringToInteger(const std::string& s) {
    long i;
    if (canConvertToInteger(s, i))
        return (int) i;
    else
        throw std::invalid_argument("Error. Input string is not an integer.");
}

std::string integerToString(int i) {
    
    return std::string();
}
