//
//  util.h
//  Calculator
//
//  Created by Gareth George on 12/9/14.
//  Copyright (c) 2014 Gareth George. All rights reserved.
//

#ifndef __Calculator__util__
#define __Calculator__util__

#include <stdio.h>
#include <string>

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

#endif /* defined(__Calculator__util__) */
