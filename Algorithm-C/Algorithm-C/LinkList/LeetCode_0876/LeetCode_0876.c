//
//  LeetCode_0876.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0876.h"

#include "LinkList.h"

#include <stdlib.h>
/*
 中间节点
 快慢指针
 */
struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL && fast->next != NULL) {
        
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

void test_LeetCode_0876(void) {
    
    int arrL1[5] = { 1, 2, 3, 4, 5 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    int n = 2;
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    
    struct ListNode *ret = middleNode(l1->next);
    printf("链表的中间节点链表:");
    printList(ret);
}
