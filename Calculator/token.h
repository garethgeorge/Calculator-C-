//
//  token.h
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__token__
#define __Calculator__token__

#include <string>
#include <vector>
#include "Fraction.h"

using namespace std;

class Compiler;

class Token {
public:
    Token() {};
    ~Token() {};
    
    virtual string toString();
    
    virtual void compile(Compiler& p);
    
    virtual bool isOperator() { return false; };
    virtual bool isValue() { return false; };
};

class TokenValue : public Token {
private:
    Math::Fraction value;
public:
    TokenValue(int n, int d) : value(n, d) {}
    TokenValue(Math::Fraction& value) : value(value.n, value.d) {}
    TokenValue(string value) : value(value) {}
    ~TokenValue() {}
    
    string toString();
    
    void compile(Compiler& p);
    bool isValue() { return true; }
    
    Math::Fraction getValue() { return value; }
};



class ExpressionEvaluator;
class TokenOperator : public Token {
public:
    TokenOperator() {};
    ~TokenOperator() {};
    
    virtual string toString();
    
    virtual int getPriority() { return -1; };
    
    void compile(Compiler& p);
    
    bool isOperator() { return true; };
    
    virtual TokenValue eval(ExpressionEvaluator&);
};

class TokenOperatorAdd : public TokenOperator {
public:
    TokenOperatorAdd() {};
    ~TokenOperatorAdd() {};
    
    string toString();
    
    int getPriority() { return 3; };
    
    TokenValue eval(ExpressionEvaluator&);
};

class TokenOperatorSubtract : public TokenOperator {
public:
    TokenOperatorSubtract() {};
    ~TokenOperatorSubtract() {};
    
    string toString();
    
    int getPriority() { return 2; };
    
    TokenValue eval(ExpressionEvaluator&);
};

class TokenOperatorMultiply : public TokenOperator {
public:
    TokenOperatorMultiply() {};
    ~TokenOperatorMultiply() {};
    string toString();
    
    int getPriority() { return 5; };
    
    TokenValue eval(ExpressionEvaluator&);
};

class TokenOperatorDivide : public TokenOperator {
public:
    TokenOperatorDivide() {};
    ~TokenOperatorDivide() {};
    string toString();
    int getPriority() { return 4; };
    
    TokenValue eval(ExpressionEvaluator&);
};

#endif /* defined(__Calculator__token__) */
