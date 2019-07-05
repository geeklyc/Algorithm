//
//  ArrayQueue.h
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/31.
//  Copyright © 2019 Giga. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include <stdio.h>

typedef int ArrayQueueData;

typedef struct array_queue {
    
    int size;/*队列的大小*/
    int num; /*当前存储数据的大小*/
    int head;/*队列的头*/
    int tail;/*队列的尾*/
    int *array;/*数据存储区*/
}ArrayQueue;

void arrayQueueTest(void);

#endif /* ArrayQueue_h */
