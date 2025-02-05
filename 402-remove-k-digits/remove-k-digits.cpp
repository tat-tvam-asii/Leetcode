class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num){
            while(!st.empty() && c < st.top() && k){
                k--;
                st.pop();
            }
            st.push(c);
        }
        while(k-- && !st.empty()) st.pop();
        if(st.empty()) return "0";
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};