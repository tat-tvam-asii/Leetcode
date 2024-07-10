class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(),m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                if(i == 0){
                    dp[i][j] = j;
                    continue;
                }
                if(j == 0){
                    dp[i][j] = i;
                    continue;
                }
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[n][m];
    }
};