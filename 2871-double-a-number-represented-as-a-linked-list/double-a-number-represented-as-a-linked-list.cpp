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
    int helper(ListNode* node){
        if(!node) return 0;
        int value = 2*node->val + helper(node->next);
        node->val = value % 10;
        return value / 10;
    }

    ListNode* doubleIt(ListNode* head) {
       int help = helper(head);
       if(help == 0) return head;
       else{
           ListNode* newhead = new ListNode(help,head);
           return newhead;
       }
    }
};