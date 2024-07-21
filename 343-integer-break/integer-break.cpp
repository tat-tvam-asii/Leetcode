class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,1));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                dp[i][j] = max({dp[i][j],dp[i][j-1],j*dp[i-j][i-j]});
            }
        }
        if(dp[n][n] == n) return dp[n][n-1];
        return dp[n][n];
    }
};