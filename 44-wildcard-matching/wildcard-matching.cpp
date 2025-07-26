class Solution {
public:
    bool isMatch(string s, string p) {
        string temp = "";
        for(int i = 0;i < p.length();i++){
            temp.push_back(p[i]);
            while(i < p.length() - 1 && p[i] == '*' && p[i+1] == '*') i++;
        }
        p = temp;
        int m = s.length(),n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        if(n && p[0] == '*') dp[0][1] = true;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};