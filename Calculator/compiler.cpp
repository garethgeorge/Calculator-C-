//
//  compiler.cpp
//  Calculator
//
//  Created by Gareth George on 12/10/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include "compiler.h"
#include "util.h"
#include <iostream>

using namespace std;
Compiler::Compiler(vector<Token*>& _expr) {
    for(auto it = _expr.rbegin(); it != _expr.rend(); ++it) {
        expression.push(*it);
    }
    
    parse();
}

Compiler::Compiler(Parser& p) {
    for(auto it = p.terms.rbegin(); it != p.terms.rend(); ++it) {
        expression.push(*it);
    }
    parse();
}

Compiler::~Compiler() {
    
}

void Compiler::parse() {
    while(!expression.empty()) {
        Token* t = expression.top();
        expression.pop();
        if(t->isOperator()){
            TokenOperator* op = (TokenOperator*) t;
            op->compile(*this);
        } else if(t->isValue()) {
            pushToken(*t);
        }
    }
}

void Compiler::popValue(int curPriority) {
    Token* t = expression.top();
    expression.pop();
    
    if(t->isOperator()) {
        TokenOperator* op = (TokenOperator*) t;
        op->compile(*this);
    } else if(t->isValue()) {
        t->compile(*this);
        if (!expression.empty()) {
            TokenOperator* nextOp = (TokenOperator*) expression.top();
            
            if (nextOp->getPriority() > curPriority) {
                expression.pop();
                processOperator(*nextOp);
            }
        }
    }
}

void Compiler::processOperator(TokenOperator& op) {
    popValue(op.getPriority());
    pushToken(op);
}


string Compiler::toString() {
    stack<Token*> stuffz = stack<Token*>();
    string str = string();
    
    for(auto it = program.begin(); ;) {
        Token* token = *it;
        str.append(token->toString());
        it++;
        if (it != program.end())
            str.append(", ");
        else
            break;
    }
    
    str.append(" -> ");
    
    str.append(program.toString());
    
    return str;
}





string popStringValue(ExpressionStack &stack) {
    if(stack.empty()){
        return "NULL";
    } else {
        Token* top = stack.top();
        stack.pop();
        
        if(top->isOperator()){
            string arg2 = popStringValue(stack);
            string arg1 = popStringValue(stack);
            string str = string();
            str.append("(");
            str.append(arg1);
            str.append(top->toString());
            str.append(arg2);
            str.append(")");
            return str;
        } else if(top->isValue()) {
            return top->toString();
        }
    }
    return "NULL";
}


string Expression::toString() {
    ExpressionStack stack = ExpressionStack(this);
    return popStringValue(stack);
}

