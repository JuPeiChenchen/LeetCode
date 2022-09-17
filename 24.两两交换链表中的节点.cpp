/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* cur = head->next;
        ListNode* pre = head;
        ListNode* x = newHead;
        while(cur->next != NULL && cur->next->next != NULL) {
            ListNode* c = cur->next->next;
            ListNode* p = cur->next;
            pre->next = cur->next;
            x->next = cur;
            cur->next = pre;
            x = pre;
            cur = c;
            pre = p;
        }
        pre->next = cur->next;
        x->next = cur;
        cur->next = pre;
        head = newHead->next;
        delete newHead;
        return head;
    }
};
// @lc code=end

