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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int sz = 0;
        while(temp) sz++,temp = temp->next;
        if(sz == 0) return head;
        k %= sz;
        if(k == 0) return head;
        ListNode *slow = head,*fast = head;
        while(k--) fast = fast->next;
        while(fast->next) fast = fast->next,slow = slow->next;
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};