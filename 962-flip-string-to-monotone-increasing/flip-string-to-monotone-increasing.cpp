class Solution {
public:
    int solve(string& s,int i,bool flag,vector<vector<int>>& dp){
        if(i == s.length()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(flag) return dp[i][flag] = !(s[i] == '1') + solve(s,i+1,true,dp);
        else return dp[i][flag] = (s[i] == '1') + min(solve(s,i+1,false,dp),solve(s,i+1,true,dp));
    }

    int minFlipsMonoIncr(string s) {
        int i = 0;
        for(i = 0;i < s.length();i++){
            if(s[i] == '1') break;
        }
        vector<vector<int>> dp(s.length(),vector<int>(2,-1));
        return min(solve(s,i,false,dp),solve(s,i,true,dp));
    }
};