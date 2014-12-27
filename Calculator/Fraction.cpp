//
//  Fraction.cpp
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#include "Fraction.h"
#include <regex>
#include <cstdlib>


namespace Math {
    using namespace std;
    
    regex fracRegex = std::regex("(-?)([0-9]+)_?([0-9])*/?([0-9]*)");
    
    Fraction::Fraction(std::string value) {
        smatch match;
        regex_search(value, match, fracRegex);
        string sign = match[1];
        string whole = match[2];
        string numer = match[3];
        string denom = match[4];
        
        d = denom.length() > 0 ? stoi(denom) : 1;
        n = numer.length() > 0 ? stoi(numer) + stoi(whole) * d : stoi(whole);
        
        if(d != 1) {
            int gcd = Math::gcd(abs(n), d);
            d = d / gcd;
            n = n / gcd;
        }
    }
    
    string Fraction::toString() {
        if(d == 1){
            return to_string(n);
        } else if(abs(n) < d) {
            string str = string();
            str.append(to_string(n));
            str.append("/");
            str.append(to_string(d));
            return str;
        } else {
            string str = string();
            int whole = n / d;
            int numer = abs(n) % d;
            str.append(to_string(whole));
            str.append("_");
            str.append(to_string(numer));
            str.append("/");
            str.append(to_string(d));
            return str;
        }
        return "<fraction>";
    }
}