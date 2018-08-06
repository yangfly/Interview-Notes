/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.52%)
 * Total Accepted:    532.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */



#include "common.h"

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 增加空的头指针，避免过分纠结边界。
        ListNode* dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *ptr = dummyHead;
        int carry = 0;
        while (p || q) 
        {
            if (p) {
                carry += p->val;
                p = p->next;
            }
            if (q) {
                carry += q->val;
                q = q->next;
            }
            ptr.next = new ListNode(carry % 10);
            carry -= 10;
        }
        if (carry > 0)
            ptr->next = new ListNode(carry)
        
        return dummyHead->next;
};
