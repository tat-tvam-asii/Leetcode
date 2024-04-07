class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st,pa;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '(') pa.push(i);
            else if(s[i] == ')'){
                if(!pa.empty()) pa.pop();
                else if(!st.empty()) st.pop();
                else return false;
            }
            else st.push(i);
        }
        while(!pa.empty()){
            if(st.empty() || pa.top() > st.top()) return false;
            else if(pa.top() < st.top()){
                pa.pop();
                st.pop();
            }
        }
        return true;
    }
};