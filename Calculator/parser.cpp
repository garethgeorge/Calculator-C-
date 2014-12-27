//
//  parser.cpp
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include "parser.h"
#include "token.h"
#include <regex>

using namespace std;

Parser::Parser(std::string expr) {
    regex number("[\\+\\-]?[0-9]+_?[0-9]*/?[0-9]*|[\\+\\-\\*\\/\\^\\%\\(\\)]");
    sregex_iterator it(expr.begin(),expr.end(), number);
    sregex_iterator it_end; // ending condition that we can check against.
    
    while (it != it_end) {
        string cur = it->str();
        if(regex_search(cur, Math::fracRegex)){
            terms.insert(terms.end(), new TokenValue(cur));
        } else {
            if (cur == "+"){
                terms.insert(terms.end(), new TokenOperatorAdd());
            } else if (cur == "-"){
                terms.insert(terms.end(), new TokenOperatorSubtract());
            } else if (cur == "*"){
                terms.insert(terms.end(), new TokenOperatorMultiply());
            } else if (cur == "/"){
                terms.insert(terms.end(), new TokenOperatorDivide());
            }
        }
        ++it;
    }
}

Parser::~Parser() {
}

string Token::toString() {
    return string("[BASE]");
}

string TokenValue::toString() {
    return value.toString();
}


string TokenOperator::toString() {
    return "[OPERATOR]";
}

string TokenOperatorAdd::toString() {
    return "+";
}

string TokenOperatorSubtract::toString() {
    return "-";
}

string TokenOperatorMultiply::toString() {
    return "*";
}

string TokenOperatorDivide::toString() {
    return "/";
}

