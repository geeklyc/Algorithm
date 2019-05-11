//
//  LinkStack.h
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/1.
//  Copyright © 2019 Giga. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>

struct StackNode {
    
    char val;
    struct StackNode *next;
};

struct StackLink {
  
    struct StackNode *top; // 栈顶
    int count; // 栈数量
};

typedef struct StackLink Stack;

Stack *stackCreate(void);

int stackIsEmpty(Stack *s);

int stackPop(Stack *s, char *e);

int stackPush(Stack *s, char e);

int stackTop(Stack *s, char *e);

void stackDump(Stack *s);

void stackDestory(Stack *s);

void stackTest(void);

#endif /* LinkStack_h */
