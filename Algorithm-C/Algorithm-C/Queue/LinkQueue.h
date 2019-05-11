//
//  LinkQueue.h
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>

struct QueueNode {
    
    char val;
    struct QueueNode *next;
};

struct QueueLink {
    
    struct QueueNode *front; // 队头
    struct QueueNode *rear; // 队尾
    int count; // 队大小
};

typedef struct QueueLink Queue;

Queue *queueCreate(void);

int queueIsEmpty(Queue *q);

int queueLength(Queue *q);

int queuePush(Queue *q, char e);

int queuePop(Queue *q, char *e);

void queueDestory(Queue *q);

void queueDump(Queue *q);

void queueTest(void);

#endif /* LinkQueue_h */
