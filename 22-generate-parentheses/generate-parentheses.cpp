class Solution {
public:
    void solve(vector<string>&ans,int open,int close,string otp){
        if(open > close) return;
        if(close == 0){
            ans.push_back(otp);
            return;
        }
        if(open == 0){
            while(close--) otp += ')';
            ans.push_back(otp);
            return;
        }
        solve(ans,open-1,close,otp+'(');
        solve(ans,open,close-1,otp+')');
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string otp = "";
        int open = n,close = n;
        solve(ans,open,close,otp);
        return ans;
    }
};