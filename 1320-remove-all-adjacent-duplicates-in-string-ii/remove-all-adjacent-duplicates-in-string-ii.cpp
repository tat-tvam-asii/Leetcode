class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c : s){
            if(!st.empty() && st.top().first == c){
                st.push({c,st.top().second + 1});
                if(st.top().second == k){
                    int cnt = k;
                    while(cnt--) st.pop();
                }
            }
            else st.push({c,1});
        }
        string ans;
        while(!st.empty()) ans += st.top().first,st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};