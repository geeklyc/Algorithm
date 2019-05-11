//
//  ListNode.h
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/1.
//  Copyright © 2019 Giga. All rights reserved.
//

#ifndef ListNodeDemo_h
#define ListNodeDemo_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int value);

struct ListNode *createList(int arr[], int size);

void printList(struct ListNode *list);

#endif /* ListNodeDemo_h */
