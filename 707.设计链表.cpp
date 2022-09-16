/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > size - 1) {
            return -1;
        }
        ListNode* p = head->next;
        while(index--) {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head->next;
        head->next = p;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        ListNode* p = new ListNode(val);
        p->next = NULL;
        cur->next = p;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        ListNode* p = new ListNode(val);
        ListNode* cur = head;
        while(index--) {
            cur = cur->next;
        }
        p->next = cur->next;
        cur->next = p;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > size - 1) {
            return;
        }
        ListNode* cur = head;
        while(index--) {
            cur = cur->next;
        }
        ListNode* p = cur->next;
        cur->next = p->next;
        delete p;
        size--;
    }
private:
    int size;
    ListNode* head;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

