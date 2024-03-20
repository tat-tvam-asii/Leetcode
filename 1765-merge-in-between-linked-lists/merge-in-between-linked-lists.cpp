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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *s = list1,*e = list1,*temp = list1;
        while(a > 0 || b > 0){
            temp = temp->next;
            if(--a > 0) s = temp;
            if(b-- > 0) e = temp;
        }
        s->next = list2;
        temp = list2;
        while(temp->next) temp = temp->next;
        temp->next = e->next;
        return list1;
    }
};