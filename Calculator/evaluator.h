//
//  evaluator.h
//  Calculator
//
//  Created by Gareth George on 12/12/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__evaluator__
#define __Calculator__evaluator__

#include <stdio.h>
#include "compiler.h"

using namespace std;

class Expression;
class TokenValue;

class ExpressionEvaluator {
private:
    stack<Token*> expression;
public:
    ExpressionEvaluator(Expression& expr);
    ~ExpressionEvaluator(){}
    TokenValue popValue();
};

#endif /* defined(__Calculator__evaluator__) */
