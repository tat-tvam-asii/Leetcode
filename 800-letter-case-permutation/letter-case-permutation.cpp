class Solution {
public:
    void solve(set<string>&st,string s,string op){
        if(s.empty()){
            st.insert(op);
            return;
        }
        string op1 = op,op2 = op;
        op1 += tolower(s[0]);
        op2 += toupper(s[0]);
        s.erase(s.begin());
        solve(st,s,op1);
        solve(st,s,op2);
    }

    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> ans;
        set<string> st;
        solve(st,s,op);
        for(auto i : st) ans.push_back(i);
        return ans;
    }
};