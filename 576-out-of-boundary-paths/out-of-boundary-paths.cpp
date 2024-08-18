class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int m,int n,int N,int i,int j,vector<vector<vector<int>>>& dp){
        if(i == m || j == n || i < 0 || j < 0) return 1;
        if(N == 0) return 0;
        if(dp[i][j][N] != -1) return dp[i][j][N];
        return  dp[i][j][N] = ((solve(m,n,N-1,i-1,j,dp) + solve(m,n,N-1,i+1,j,dp)) % mod
        + (solve(m,n,N-1,i,j-1,dp) + solve(m,n,N-1,i,j+1,dp)) % mod) % mod;
    }

    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(N+1,-1)));
        return solve(m,n,N,i,j,dp);
    }
};