//
//  LeetCode_0002.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/1.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0002.h"

#include <stdlib.h>

#include "LinkList.h"
/*
 两字符串之和
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    struct ListNode *p = head;
    
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = sum % 10;
        
        p->next = temp;
        p = p->next;
        
        if (l1 != NULL) {
            
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            
            l2 = l2->next;
        }
    }
    
    if (carry == 1) {
        
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = 1;
        temp->next = NULL;
        p->next = temp;
    }
    
    return head->next;
}

void test_LeetCode_0002(void) {
    
    int arrL1[3] = { 2, 4, 3 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    
    int arrL2[3] = { 5, 6, 4 };
    int len2 = sizeof(arrL2)/ sizeof(arrL2[0]);
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    
    struct ListNode *l2 = createList(arrL2, len2);
    printf("l2链表:");
    printList(l2->next);
    
    struct ListNode *ret = addTwoNumbers(l1->next, l2->next);
    printf("相加之和的结果:");
    printList(ret);
}
