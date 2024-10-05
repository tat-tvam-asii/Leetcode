class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(char c : s){
            if(c == '#'){
                if(!st.empty()) st.pop();
            }
            else st.push(c);
        }
        s = "";
        while(!st.empty()) s += st.top(),st.pop();
        for(char c : t){
            if(c == '#'){
                if(!st.empty()) st.pop();
            }
            else st.push(c);
        }
        t = "";
        while(!st.empty()) t += st.top(),st.pop();
        return s == t;
    }
};