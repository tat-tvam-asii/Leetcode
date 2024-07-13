class Solution {
public:
    const int mod = 1e9 + 7;

    int numDecodings(string s) {
        int l = s.length();
        vector<int> dp(l+1);
        dp[l] = 1;
        for(int i = l-1;i >= 0;i--){
            if(s[i] == '0') dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(s[i] == '*') dp[i] = (9ll*dp[i]) % mod;
                if(i < l-1 && s[i+1] == '*'){
                    if(s[i] == '1') dp[i] = (dp[i] + 9ll*dp[i+2]) % mod;
                    else if(s[i] == '2') dp[i] = (dp[i] + 6ll*dp[i+2]) % mod;
                    else if(s[i] == '*') dp[i] = (dp[i] + 15ll*dp[i+2]) % mod;
                }
                else if(i < l-1 && (s[i] == '*' || s[i] == '1' || s[i] == '2'&&s[i+1] < '7')){
                    dp[i] = (dp[i] + dp[i+2]) % mod;
                    if(s[i] == '*' && s[i+1] < '7') dp[i] = (dp[i] + dp[i+2]) % mod;
                }
            }
        }
        return dp[0];
    }
};