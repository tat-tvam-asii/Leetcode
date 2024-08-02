class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(!i){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int mn = INT_MAX;
                for(int k = 0;k < n;k++){
                    if(k != j) mn = min(mn,dp[i-1][k]);
                }
                dp[i][j] = grid[i][j] + mn;
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};