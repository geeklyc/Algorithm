//
//  ArrayStack.h
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/31.
//  Copyright © 2019 Giga. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>

typedef int ArrayStackData;

typedef struct array_stack {
    
    int size;
    int top;
    ArrayStackData *array;
}ArrayStack;

void arrayStackTest(void);

#endif /* ArrayQueue_h */
