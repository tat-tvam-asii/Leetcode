class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        for(char c : s) freq[c-'a']++;
        stack<char> st;
        unordered_map<char,int> mp;
        for(char c : s){
            if(mp[c]){
                freq[c-'a']--;
                continue;
            }
            while(!st.empty() && c < st.top() && freq[st.top()-'a'] > 1){
                freq[st.top()-'a']--;
                mp[st.top()]--;
                st.pop();
            }
            st.push(c);
            mp[c]++;
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};