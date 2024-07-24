class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(),stones.end(),0);
        int s = total/2;
        vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
        for(int i = 0;i <= n;i++) dp[i][0] = true;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= s;j++){
                if(stones[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        for(int j = s;j >= 0;j--) if(dp[n][j]) return (total - 2*j);
        return 0;
    }
};