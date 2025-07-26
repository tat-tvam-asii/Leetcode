class Solution {
public:
    bool solve(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(j == 0) return i == 0;
        if(i == 0){
            if(j == 0) return true;
            else{
                while(j > 0){
                    if(p[j-1] != '*') return false;
                    j--;
                }
                return true;
            }
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == p[j-1]) return dp[i][j] = solve(s,p,i-1,j-1,dp);
        else{
            if(p[j-1] == '?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
            else if(p[j-1] == '*') return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i-1,j-1,dp) || solve(s,p,i,j-1,dp);
            else return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s,p,m,n,dp);
    }
};