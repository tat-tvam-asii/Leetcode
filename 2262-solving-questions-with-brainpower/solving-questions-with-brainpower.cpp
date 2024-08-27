class Solution {
public:
    long long solve(vector<vector<int>>& questions,int i,vector<long long>& dp){
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(questions[i][0]+solve(questions,i+questions[i][1]+1,dp),solve(questions,i+1,dp));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
};