//
//  strhelper.hpp
//  Interpreter
//
//  Created by Juan Trejo on 10/4/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef strhelper_hpp
#define strhelper_hpp

#include <stdio.h>
#include <string>

/* *
 * @brief
 * @param s
 * @return
 */
bool isInteger(const std::string& s);

/* *
 * @brief
 * @param s
 * @return
 */
int stringToInteger(const std::string& s);

/* *
 * @brief
 * @param i
 * @return
 */
std::string integerToString(int i);

#endif /* strhelper_hpp */
