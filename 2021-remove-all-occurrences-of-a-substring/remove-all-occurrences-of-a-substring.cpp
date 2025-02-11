class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(char c : s){
            st.push(c);
            int j = part.length() - 1;
            string temp;
            while(!st.empty() && j >= 0 && st.top() == part[j]){
                temp += st.top();
                st.pop();
                j--;
            }
            if(j != -1){
                reverse(temp.begin(),temp.end());
                for(char ch : temp) st.push(ch);
            }
        }
        string ans;
        while(!st.empty()) ans += st.top(),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};