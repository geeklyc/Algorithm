//
//  LinkStack.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/1.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LinkStack.h"

#include <stdlib.h>

Stack *stackCreate(void) {
    
    Stack *p = (Stack *)malloc(sizeof(struct StackNode));
    if (p != NULL) {
        p->count = 0;
        p->top = NULL;
        return p;
    }
    
    return NULL;
}

int stackIsEmpty(Stack *s) {
    
    return s->count == 0 ? 1 : 0;
}

int stackPop(Stack *s, char *e) {
    
    if (stackIsEmpty(s)) {
        
        return 0;
    }
    
    *e = s->top->val;
    struct StackNode *p = s->top;
    s->top = p->next;
    s->count--;
    
    free(p);
    
    return 1;
}

int stackPush(Stack *s, char e) {
    
    struct StackNode *p = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (p == NULL) {
        
        return 0;
    }
    p->val = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    
    return 1;
}

int stackTop(Stack *s, char *e) {
    
    if (stackIsEmpty(s)) {
        
        return 0;
    }
    
    *e = s->top->val;
    
    return 1;
}

void stackDump(Stack *s) {
    
    printf("栈大小 = %d\n", s->count);
    int i = 0;
    struct StackNode *p = s->top;
    while (p != NULL) {
        
        printf("node[%d] = %c\n", i, p->val);
        i++;
        p = p->next;
    }
}

void stackDestory(Stack *s) {
    
    if (s == NULL) {
        
        return;
    }
    
    if (stackIsEmpty(s)) {
        
        return;
    }
    
    char e;
    while (!stackIsEmpty(s)) {
        
        stackPop(s, &e);
    }
    
    free(s);
}

void stackTest(void) {
    
    Stack *stack = stackCreate();
    if (stack == NULL) {
        
        printf("创建栈失败\n");
        return;
    }
    
    char arr[] = { 'a', 'b', 'c', 'd' };
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    
        if (stackPush(stack, arr[i]) == 1) {
            
            printf("%c 入栈成功\n", arr[i]);
        }
    }
    
    stackDump(stack);
    
    char e;
    if (stackPop(stack, &e) != 1) {
        
        printf("%c 出栈失败\n", e);
    }
    
    stackDump(stack);
    
    stackPush(stack, e);
    
    stackDump(stack);
}
