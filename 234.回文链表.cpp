/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {

        ListNode* cur  = head;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }
        vector<int> vec(length, 0); // 给定vector的初始长度，这样避免vector每次添加节点重新开辟空间
        cur = head;
        int index = 0;
        while (cur) {
            vec[index++] = cur->val;
            cur = cur->next;
        }
        // 比较数组回文
        for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            if (vec[i] != vec[j]) return false;
        }
        return true;
    }
};*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head; // 慢指针，找到链表中间分位置，作为分割
        ListNode* fast = head;
        ListNode* pre = head; // 记录慢指针的前一个节点，用来分割链表
        int i = 0;
        while (fast && fast->next) {
            cout<<i<<endl;
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //cout<<pre->val;
        pre->next = nullptr; // 分割链表

        ListNode* cur1 = head;  // 前半部分
        ListNode* cur2 = reverseList(slow); // 反转后半部分，总链表长度如果是奇数，cur2比cur1多一个节点

        // 开始两个链表的比较
        while (cur1) {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
// @lc code=end

