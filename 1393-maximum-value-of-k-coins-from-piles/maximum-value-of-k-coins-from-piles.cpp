class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for(int i = 0;i < n;i++){
            for(int j = 1;j < piles[i].size();j++){
                piles[i][j] += piles[i][j-1];
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k;j++){
                dp[i][j] = dp[i-1][j];
                for(int l = 1;l <= min(j,(int)piles[i-1].size());l++){
                    dp[i][j] = max(dp[i][j],piles[i-1][l-1] + dp[i-1][j-l]);
                }
            }
        }
        return dp[n][k];
    }
};