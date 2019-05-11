//
//  ListNode.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/1.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "ListNodeDemo.h"

#include <stdlib.h>

struct ListNode *createNode(int value) {
    
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    temp->val = value;
    return temp;
}

struct ListNode *createList(int arr[], int size) {
    
    struct ListNode *head = createNode(0);
    struct ListNode *p = head;
    
    for (int i = 0; i < size; i++) {
        
        struct ListNode *temp = createNode(arr[i]);
        p->next = temp;
        p = p->next;
    }
    return head;
}

void printList(struct ListNode *list) {
    
    struct ListNode *p = list;
    while (p != NULL) {
        
        printf("%d", p->val);
        p = p->next;
        if (p != NULL) {
            
            printf("->");
        }
    }
    printf("\n");
}
