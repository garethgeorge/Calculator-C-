//
//  evaluator.cpp
//  Calculator
//
//  Created by Gareth George on 12/12/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include "evaluator.h"

using namespace std;

ExpressionEvaluator::ExpressionEvaluator(Expression& expr) {
    for(auto it = expr.begin(); it != expr.end(); ++it) {
        expression.push(*it);
    }
}
TokenValue ExpressionEvaluator::popValue() {
    Token* next = expression.top();
    expression.pop();
    if(next->isOperator()){
        TokenOperator* op = (TokenOperator*) next;
        return op->eval(*this);
    } else if(next->isValue()){
        return *((TokenValue*) next);
    }
    throw(0);
}
