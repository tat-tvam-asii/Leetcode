class Solution {
public:
    const int mod = 1e9 + 7;

    int numDecodings(string s) {
        int l = s.length();
        int dp = 0,dp1 = 1,dp2 = 0;
        for(int i = l-1;i >= 0;i--){
            if(s[i] == '0') dp = 0;
            else{
                dp = dp1;
                if(s[i] == '*') dp = (9ll*dp) % mod;
                if(i < l-1 && s[i+1] == '*'){
                    if(s[i] == '1') dp = (dp + 9ll*dp2) % mod;
                    else if(s[i] == '2') dp = (dp + 6ll*dp2) % mod;
                    else if(s[i] == '*') dp = (dp + 15ll*dp2) % mod;
                }
                else if(i < l-1 && (s[i] == '*' || s[i] == '1' || s[i] == '2'&&s[i+1] < '7')){
                    dp = (dp + dp2) % mod;
                    if(s[i] == '*' && s[i+1] < '7') dp = (dp + dp2) % mod;
                }
            }
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};