class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size(),j = 0;
        stack<int> st;
        for(int i : pushed){
            st.push(i);
            while(j < n && !st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return j == n;
    }
};