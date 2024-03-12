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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0;i<v.size();i++){
            int sum = 0;
            for(int j=i;j<v.size();j++){
                sum += v[j];
                if(sum == 0){
                    v.erase(v.begin()+i,v.begin()+j+1);
                    j -= (j-i+1);
                }
            }
        }
        ListNode *newhead,*temp2;
        if(!v.empty()) newhead = new ListNode(v[0]);
        temp2 = newhead;
        for(int i=1;i<v.size();i++){
            temp2 ->next = new ListNode(v[i]);
            temp2 = temp2->next;
        }
        return newhead;
    }
};