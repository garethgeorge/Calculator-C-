//
//  parser.h
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__parser__
#define __Calculator__parser__

#include "Fraction.h"

using namespace std;

class Token;
class Parser {
public:
    Parser(string expr);
    ~Parser();
    
    vector<Token*> terms;
};

#endif /* defined(__Calculator__parser__) */
