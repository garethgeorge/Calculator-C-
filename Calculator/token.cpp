//
//  token.cpp
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include "token.h"
#include "compiler.h"
#include "evaluator.h"

void Token::compile(Compiler& c) {
    c.pushToken(*this);
}

void TokenValue::compile(Compiler& c) {
    c.pushToken(*this);
}

void TokenOperator::compile(Compiler& c) {
    c.popValue(getPriority());
    c.pushToken(*this);
}

TokenValue TokenOperator::eval(ExpressionEvaluator& eval) {
    Math::Fraction val = Math::Fraction(0,0);
    return TokenValue(val);
}

TokenValue TokenOperatorMultiply::eval(ExpressionEvaluator& eval) {
    TokenValue op2 = eval.popValue();
    TokenValue op1 = eval.popValue();
    Math::Fraction val = op2.getValue() * op1.getValue();
    return TokenValue(val);
}

TokenValue TokenOperatorSubtract::eval(ExpressionEvaluator& eval) {
    TokenValue op2 = eval.popValue();
    TokenValue op1 = eval.popValue();
    Math::Fraction val = op1.getValue() - op2.getValue();
    return TokenValue(val);
}

TokenValue TokenOperatorAdd::eval(ExpressionEvaluator& eval) {
    TokenValue op2 = eval.popValue();
    TokenValue op1 = eval.popValue();
    Math::Fraction val = op1.getValue() + op2.getValue();
    return TokenValue(val);
}

TokenValue TokenOperatorDivide::eval(ExpressionEvaluator& eval) {
    TokenValue op2 = eval.popValue();
    TokenValue op1 = eval.popValue();
    Math::Fraction val = op1.getValue() / op2.getValue();
    return TokenValue(val);
}