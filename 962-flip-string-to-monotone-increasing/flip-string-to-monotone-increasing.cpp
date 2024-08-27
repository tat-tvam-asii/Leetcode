class Solution {
public:

    int minFlipsMonoIncr(string s) {
        int i = 0,l = s.length();
        for(i = 0;i < l;i++){
            if(s[i] == '1') break;
        }
        vector<vector<int>> dp(l+1,vector<int>(2,0));
        for(int i = l-1;i >= 0;i--){
            dp[i][1] = (s[i] != '1') + dp[i+1][1];
            dp[i][0] = (s[i] == '1') + min(dp[i+1][0],dp[i+1][1]);
        }
        return min(dp[0][0],dp[0][1]);
    }
};