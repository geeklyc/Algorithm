//
//  LeetCode_0141.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0141.h"

#include "LinkList.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 环形链表
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            
            return true;
        }
    }
    return false;
}

struct ListNode *create_cycle_list() {
    
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1;
    
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 2;
    
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 3;
    
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 4;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    
    return node1;
}

void test_LeetCode_0141(void) {
    
    int arrL1[4] = { 1, 2, 3, 4 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    
    struct ListNode *l2 = create_cycle_list();
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    bool isCycle = hasCycle(l1->next);
    printf("是否存在环:%s\n",isCycle ? "是" : "不是");
    
    bool isCycle1 = hasCycle(l2);
    printf("是否存在环:%s\n",isCycle1 ? "是" : "不是");
}
