class Solution {
public:
    int solve(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]) return dp[i][j] = solve(word1,word2,i-1,j-1,dp);
        
        int in = solve(word1,word2,i,j-1,dp);
        int d = solve(word1,word2,i-1,j,dp);
        int r = solve(word1,word2,i-1,j-1,dp);
        return dp[i][j] = 1 + min({in,d,r});
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(),n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i = 0;i <= m;i++) dp[i][0] = i;
        for(int j = 0;j <= n;j++) dp[0][j] = j;
        return solve(word1,word2,m,n,dp);
    }
};