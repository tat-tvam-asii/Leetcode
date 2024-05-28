class Solution {
public:
    void solve(vector<string>&ans,int i,string s){
        if(i == s.length()){
            ans.push_back(s);
            return;
        }
        solve(ans,i+1,s);
        if(isalpha(s[i])){
            s[i] ^= (1 << 5);
            solve(ans,i+1,s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int i = 0;
        solve(ans,i,s);
        return ans;
    }
};