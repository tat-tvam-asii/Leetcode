class Solution {
public:
    void solve(vector<string>&ans,int i,string s,string op){
        if(i == s.length()){
            ans.push_back(op);
            return;
        }
        string op1 = op,op2 = op;
        while(isdigit(s[i])){
            op1 += s[i];
            op2 += s[i];
            i++;
        }
        if(i == s.length()){
            ans.push_back(op1);
            return;
        }
        op1 += tolower(s[i]);
        op2 += toupper(s[i]);
        i++;
        solve(ans,i,s,op1);
        solve(ans,i,s,op2);
    }

    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> ans;
        int i = 0;
        solve(ans,i,s,op);
        return ans;
    }
};