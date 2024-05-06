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
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = head->next;
        deque<ListNode*> dq;
        dq.push_back(head);
        while(temp){
            while(!dq.empty() && temp->val > dq.back()->val){
                dq.pop_back();
            }
            dq.push_back(temp);
            temp = temp->next;
        }
        head = dq.front();
        temp = head;
        dq.pop_front();
        while(!dq.empty()){
            temp->next = dq.front();
            temp = temp->next;
            dq.pop_front();
        }
        temp->next = NULL;
        return head;
    }
};