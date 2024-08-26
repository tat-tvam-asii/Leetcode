class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int n,int k,int target,vector<vector<int>>& dp){
        if(dp[n][target] != -1) return dp[n][target];
        if(target == 0 && n == 0) return dp[n][target] = 1;
        if(target == 0 || n == 0) return dp[n][target] = 0;
        int ans = 0;
        for(int j = 1;j <= min(target,k);j++){
           ans = (ans + solve(n-1,k,target-j,dp)) % mod;
        }
        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};