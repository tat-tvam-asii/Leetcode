class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int j = 2;j <= n;j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
            else dp[0][j] = false;
        }

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1]){
                    if(j < p.length() && p[j] == '*') dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                    else dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(p[j-1] == '*') dp[i][j] = dp[i][j-1];
                    else if(p[j-1] == '.' && j < p.length() && p[j] == '*') dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                    else if(p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                    else if(j < p.length() && p[j] == '*') dp[i][j] = dp[i][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};