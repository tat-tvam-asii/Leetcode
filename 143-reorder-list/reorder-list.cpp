class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) 
        {
            st.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++)
        {
            ListNode *element = st.top();
            st.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};