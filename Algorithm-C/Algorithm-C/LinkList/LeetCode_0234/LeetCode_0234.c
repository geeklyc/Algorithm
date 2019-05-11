//
//  LeetCode_0234.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/4.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "LeetCode_0234.h"

#include "LinkList.h"
#include <stdbool.h>

/*
 回文链表
 我们使用快慢指针找中点的原理是fast和slow两个指针，每次快指针走两步，慢指针走一步，同时前置慢指针部分,等快指针走完时，慢指针的位置就是中点。同时比较slow和prev的值
 */
bool isPalindrome(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL) {
        
        return true;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        
        fast = fast->next->next;
        
        // 前置慢指针
        struct ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    // 奇数
    if (fast != NULL) {
        
        slow = slow->next;
    }
    
    while (slow != NULL) {
        
        if (prev->val != slow->val) {
            
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }
    
    return true;
}

void test_LeetCode_0234(void) {
    
    int arrL1[4] = { 1, 2, 2, 1 };
    int len1 = sizeof(arrL1)/ sizeof(arrL1[0]);
    
    int arrL2[4] = { 1, 2 };
    int len2 = sizeof(arrL2)/ sizeof(arrL2[0]);
    
    struct ListNode *l1 = createList(arrL1, len1);
    printf("l1链表:");
    printList(l1->next);
    bool flagL1 = isPalindrome(l1->next);
    printf("是否回文字符串:%s\n", flagL1 ? "是" : "不是");
    
    
    struct ListNode *l2 = createList(arrL2, len2);
    printf("l2链表:");
    printList(l2->next);
    bool flagL2 = isPalindrome(l2->next);
    printf("是否回文字符串:%s\n", flagL2 ? "是" : "不是");
}
