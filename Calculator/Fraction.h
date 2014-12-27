//
//  Fraction.h
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__Fraction__
#define __Calculator__Fraction__

#include <stdio.h>
#include <regex>
#include <string>

namespace Math {
    extern std::regex fracRegex;
    
    inline int gcd(int a, int b) {
        int c;
        while (a != 0) {
            c = a;
            a = b % a;
            b = c;
        }
        return b;
    }
    
    class Fraction {
    public:
        int n, d;
        Fraction(int n, int d){
            if(n < 0)
                d = -d, n = -n;
            
            int gcd = Math::gcd(n, d);
            this->n = n / gcd;
            this->d = d / gcd;
        }
        
        ~Fraction(){}
        
        Fraction(std::string value);
        
        std::string toString();
        inline Fraction operator* (Fraction b) {
            return Fraction(n*b.n, d*b.d);
        }
        
        inline Fraction operator/ (Fraction b) {
            return Fraction(n*b.d, d*b.n);
        }
        
        inline Fraction operator+ (Fraction b) {
            return Fraction(n*b.d+b.n*d, d*b.d);
        }
        
        inline Fraction operator- (Fraction b) {
            return Fraction(n*b.d-b.n*d, d*b.d);
        }
    };
}

#endif /* defined(__Calculator__Fraction__) */
