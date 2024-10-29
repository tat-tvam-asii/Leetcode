class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
        for(int i = 0;i < n;i++) dp[i][0] = 0;
        for(int j = 1;j < m;j++){
            for(int i = 0;i < n;i++){
                if(i-1 >= 0 && grid[i-1][j-1] < grid[i][j]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]); 
                if(grid[i][j-1] < grid[i][j]) dp[i][j] = max(dp[i][j],1+dp[i][j-1]); 
                if(i+1 < n && grid[i+1][j-1] < grid[i][j]) dp[i][j] = max(dp[i][j],1+dp[i+1][j-1]); 
            }
        }
        int mx = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                mx = max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};