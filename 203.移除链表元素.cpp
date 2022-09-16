/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
/*class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) {
            ListNode* x = head;
            head = head->next;
            delete x;
        }     
        ListNode* p = head;
        while(p != NULL && p->next != NULL) {
            if(p->next->val == val) {
                ListNode* c = p->next;
                p->next = c->next;
                delete c;
                
            }
            else{
                p = p->next;
            }
        }
        return head;
    }
};*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* p = newhead;
        while(p != NULL && p->next != NULL) {
            if(p->next->val == val) {
                ListNode* c = p->next;
                p->next = c->next;
                delete c;
                
            }
            else{
                p = p->next;
            }
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};
// @lc code=end

