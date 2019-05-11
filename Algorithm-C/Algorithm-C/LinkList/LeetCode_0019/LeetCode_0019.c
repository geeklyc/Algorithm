//
//  LeetCode_0019.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0019.h"

#include "LinkList.h"

#include <stdlib.h>
/*
 删除链表中的倒数第n个节点
 我们需要用两个指针来帮助我们解题，pre和cur指针。首先cur指针先向前走N步，如果此时cur指向空，说明N为链表的长度，则需要移除的为首元素，那么此时我们返回head->next即可，如果cur存在，我们再继续往下走，此时pre指针也跟着走，直到cur为最后一个元素时停止，此时pre指向要移除元素的前一个元素，我们再修改指针跳过需要移除的元素即可
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode *fast = dummy;
    struct ListNode *slow = dummy;
    
    for (int i = 1; i <= n + 1; i++) {
        
        fast = fast->next;
    }
    
    while (fast != NULL) {
        
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode *p = slow->next;
    slow->next = p->next;
    free(p);
    
    return dummy->next;
}

void test_LeetCode_0019(void) {
    
    int arrL1[5] = { 1, 2, 3, 4, 5 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    int n = 2;
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    
    struct ListNode *ret = removeNthFromEnd(l1->next, n);
    printf("删除倒数第%d个节点之后的链表:", n);
    printList(ret);
}
