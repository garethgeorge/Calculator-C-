//
//  compiler.h
//  Calculator
//
//  Created by Gareth George on 12/10/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__compiler__
#define __Calculator__compiler__

#include "parser.h"
#include <stack>
#include <vector>
#include "token.h"

class TokenOperator;
class TokenValue;
class Expression {
public:
    typedef std::vector<Token*>::iterator iterator;
    typedef std::vector<Token*>::reverse_iterator reverse_iterator;
private:
    std::vector<Token*> expression;
public:
    Expression(){}
    ~Expression(){}
    
    iterator begin() { return expression.begin(); }
    iterator end() { return expression.end(); }
    reverse_iterator rbegin() { return expression.rbegin(); }
    reverse_iterator rend() { return expression.rend(); }
    
    string toString();
    
    inline void push(Token* t) {expression.insert(expression.end(), t); }
};

class ExpressionStack {
private:
    Expression::reverse_iterator it_begin;
    Expression::reverse_iterator it_end;
public:
    ExpressionStack(Expression* expr) {
        it_begin = expr->rbegin();
        it_end = expr->rend();
    }
    inline Token* top() {
        return *it_begin;
    }
    inline void pop() {
        it_begin++;
    }
    inline bool empty() {
        return it_end == it_begin;
    }
};

class Compiler {
private:
    std::stack<Token*> expression;
    
    void parse();
public:
    Compiler(Parser& p);
    Compiler(std::vector<Token*>& expression);
    ~Compiler();
    
    Expression program;
    
    void popValue(int curPriority);
    void processOperator(TokenOperator& op);
    inline void pushToken(Token& t) { program.push(&t); }
    
    string toString();
};


#endif /* defined(__Calculator__compiler__) */
