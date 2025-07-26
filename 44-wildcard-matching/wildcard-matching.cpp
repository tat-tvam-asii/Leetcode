class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int j = 1;j <= n;j++){
            string temp(j,'*');
            dp[0][j] = (temp == p.substr(0,j));
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                    else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};