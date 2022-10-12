/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0;
        ListNode* cur = head;
        int result = 0;
        while(cur != NULL) {
            vector<int> :: iterator it;
            it = find(nums.begin(), nums.end(), cur->val);
            if(it != nums.end()) {
                //cout<<cur->val<<endl;
                while(cur->next != NULL && it != nums.end()) {
                    cur = cur->next;
                    it = find(nums.begin(), nums.end(), cur->val);
                }
                count++;
                cur = cur->next;
            }
            else {
                cur = cur->next;
            }
        }
        return count;
    }
};
/*class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int num : nums) {
            numsSet.emplace(num);
        }
        bool inSet = false;
        int res = 0;
        while (head != nullptr) {
            if (numsSet.count(head->val)) {
                if (!inSet) {
                    inSet = true;
                    res++;
                }
            } else {
                inSet = false;
            }
            head = head->next;
        }
        return res;
    }
};

*/
// @lc code=end

