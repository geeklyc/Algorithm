//
//  LeetCode_0021.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0021.h"

#include "LinkList.h"

#include <stdlib.h>
/*
 合并两个有序链表
 新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，所以最终会有一个链表先完成插入所有元素，则直接另一个未完成的链表直接链入新链表的末尾
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if (l1 == NULL) {
        
        return l2;
    }
    
    if (l2 == NULL) {
        
        return l1;
    }
    
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    struct ListNode *p = head;
    while (l1 != NULL && l2 != NULL) {
        
        if (l1->val > l2->val) {
            
            p->next = l1;
            l1 = l1->next;
        }
        else {
            
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    if (l1 != NULL) {
        
        p->next = l1;
    }
    
    if (l2 != NULL) {
        
        p->next = l2;
    }
    
    p = head->next;
    free(head);
    
    return p;
}

void test_LeetCode_0021(void) {
    
    int arrL1[3] = { 4, 2, 1 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    
    int arrL2[3] = { 4, 3, 1 };
    int len2 = sizeof(arrL2)/ sizeof(arrL2[0]);
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    
    struct ListNode *l2 = createList(arrL2, len2);
    printf("l2链表:");
    printList(l2->next);
    
    struct ListNode *ret = mergeTwoLists(l1->next, l2->next);
    printf("合并后的链表:");
    printList(ret);
}
