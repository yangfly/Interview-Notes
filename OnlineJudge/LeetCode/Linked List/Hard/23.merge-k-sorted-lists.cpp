/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (29.47%)
 * Total Accepted:    249K
 * Total Submissions: 845.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while (l1 != nullptr || l2 != nullptr) {
            if (l2 == nullptr || (l1 != nullptr && l1->val <= l2->val)) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p = head->next;
        delete head;
        return p;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        // 步长
        for (int step = 1; step < lists.size(); step *= 2)
            for (int i = 0; i < lists.size(); i += step * 2) {
                if (i + step > lists.size()) break; // notice
                lists[i] = mergeTwoLists(lists[i], lists[i+step]);
            }
        return lists[0];
    }
};

// 采用优先队列，小顶堆
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode dummy(0);
    	ListNode* tail = &dummy;
    	auto cmp = [](ListNode *lhs, ListNode *rhs) {return lhs->val > rhs->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto p : lists){
        	if(p != nullptr){
        		q.push(p);
        	}
        }
        while(!q.empty()){
        	auto top = q.top();
        	q.pop();
        	tail->next = top;
        	tail = tail->next;
        	if(top->next != nullptr)
        		q.push(top->next);
        }
        return dummy.next;
    }
};
