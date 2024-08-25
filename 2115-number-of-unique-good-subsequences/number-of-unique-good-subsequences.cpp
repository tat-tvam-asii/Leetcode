int mod = 1e9 + 7;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.length(), ans = 0,lastone = -1,lastzero = -1;
        
        vector<int> dp(n+1,0); 
        int i = 0;   
        for(i = 0;i < n;i++){
            if(s[i] == '0') ans = 1;
            else break;
        }  
        if(i < n) dp[++i] = 1;
        for(int j = i;j < n;j++){
            if(s[j] == '0') ans = 1;
            dp[j+1] = dp[j]*2 % mod;
            if(s[j] == '0' && lastzero >= 0) dp[j+1] = (dp[j+1] - dp[lastzero] + mod) % mod;
            if(s[j] == '1' && lastone >= 0) dp[j+1] = (dp[j+1] - dp[lastone] + mod) % mod;
            if(s[j] == '0') lastzero = j;
            else lastone = j;
            dp[j+1] %= mod;
        }     
        ans += dp[n];
        return ans; 
    }
};