//
//  LinkQueue.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LinkQueue.h"

#include <stdlib.h>

Queue *queueCreate(void) {
    
    Queue *p = (Queue *)malloc(sizeof(Queue));
    if (p != NULL) {
        p->count = 0;
        p->rear = NULL;
        p->front = NULL;
        return p;
    }
    return NULL;
}

int queueIsEmpty(Queue *q) {
    
    return q->count == 0 ? 1 : 0;
}

int queueLength(Queue *q) {
    
    return q->count;
}

int queuePush(Queue *q, char e) {

    if (q == NULL) {
        
        return 0;
    }
    
    struct QueueNode *p = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (p == NULL) {
        
        return 0;
    }
    
    p->val = e;
    p->next = NULL;
    
    if (q->front == NULL) {
        
        q->front = p;
    }
    else {
        
        q->rear->next = p;
    }
    q->rear = p;
    q->count += 1;
    
    return 1;
}

int queuePop(Queue *q, char *e) {
    
    if (q == NULL) {
        
        return 0;
    }
    
    if (queueIsEmpty(q)) {
        
        return 0;
    }
    
    *e = q->front->val;
    struct QueueNode *p = q->front;
    q->front = q->front->next;
    q->count -= 1;
    
    if (q->front == NULL) {
        
        q->rear = NULL;
    }
    
    free(p);
    
    return 1;
}

void queueDestory(Queue *q) {
    
    if (q == NULL) {
        
        return;
    }
    
    if (queueIsEmpty(q)) {
        
        return;
    }
    
    char e;
    while (!queueIsEmpty(q)) {
        
        queuePop(q, &e);
    }
    free(q);
}

void queueDump(Queue *q) {
    
    if (q == NULL) {
        
        return;
    }
    
    if (queueIsEmpty(q)) {
        
        return;
    }
    
    struct QueueNode *p = q->front;
    printf("队大小 = %d\n", q->count);
    
    int i = 0;
    while (p != NULL) {
        
        printf("node[%d] = %c\n", i, p->val);
        i++;
        p = p->next;
    }
}

void queueTest(void) {
    
    Queue *queue = queueCreate();
    if (queue == NULL) {
        
        printf("创建队失败\n");
        return;
    }
    
    char arr[] = { 'a', 'b', 'c', 'd' };
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        
        if (queuePush(queue, arr[i]) != 1) {
            
            printf("%c 入队失败\n", arr[i]);
        }
    }
    queueDump(queue);
    
    char e;
    if (queuePop(queue, &e) != 1) {
        
        printf("%c 出队失败\n", e);
    }
    printf("e = %c\n", e);
    queueDump(queue);
    
    queuePush(queue, e);
    queueDump(queue);
}
