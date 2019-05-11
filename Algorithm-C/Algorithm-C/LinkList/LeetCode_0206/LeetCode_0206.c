//
//  LeetCode_0206.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0206.h"

#include "LinkList.h"
/*
 反转链表
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *p = head;
    struct ListNode *prev = NULL;
    while (p != NULL) {
        
        struct ListNode *temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    return prev;
}

/*
 不断的进入递归函数，直到head指向最后一个节点，p指向之前一个节点，然后调换head和p的位置，再返回上一层递归函数，再交换p和head的位置，每次交换后，head节点后面都是交换好的顺序，直到p为首节点，然后再交换，首节点就成了为节点，此时整个链表也完成了翻转
 */
struct ListNode* reverseList2(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL) {
        
        return head;
    }
    
    struct ListNode *node = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return node;
}

void test_LeetCode_0206(void) {
    
    int arrL1[5] = { 5, 4, 3, 2, 1 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    
    int arrL2[2] = { 1, 2 };
    int len2 = sizeof(arrL2)/ sizeof(arrL2[0]);
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    struct ListNode *retL1 = reverseList(l1->next);
    printf("l1反转后的链表:");
    printList(retL1);
    
    
    struct ListNode *l2 = createList(arrL2, len2);
    printf("l2链表:");
    printList(l2->next);
    struct ListNode *retL2 = reverseList2(l2->next);
    printf("l2反转后的链表:");
    printList(retL2);
}
