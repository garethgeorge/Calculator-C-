//
//  main.cpp
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "parser.h"
#include "compiler.h"
#include "util.h"
#include "evaluator.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Using expression evaluator V1.0 C++ by Gareth George\n";
    
    while (true) {
        cout << "> ";
        string line;
        getline(cin, line);
        
        if (line.compare("quit") == 0) {
            break ;
        } else {
            Parser p = Parser(line);
            Compiler c = Compiler(p);
            ExpressionEvaluator eval = ExpressionEvaluator(c.program);
            
            cout << "Compiler: " << c.toString() << "\n";
            cout << "Result: " << eval.popValue().toString() << "\n";
        }
    }
    
    cout << "exited\nthanks for using expression evaluator by Gareth George\n";
    return 0;
}
