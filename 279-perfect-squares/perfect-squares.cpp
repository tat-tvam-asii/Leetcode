class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= sqrt(n);i++){
            for(int j = 1;j <= n;j++){
                int sq = i*i;
                if(j - sq >= 0) dp[j] = min(dp[j],1 + dp[j-sq]);
            }
        }
        return dp[n];
    }
};