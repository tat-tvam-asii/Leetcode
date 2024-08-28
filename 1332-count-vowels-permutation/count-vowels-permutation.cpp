class Solution {
public:
    int mod = 1e9 + 7;

    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n+1,vector<long long>(26,1));
        string vowel = "aeiou";
        for(int i = 2;i <= n;i++){
            for(char j : vowel){
                int x = j - 'a';
                if(j == 'a') dp[i][x] = dp[i-1]['e'-'a'] % mod;
                if(j == 'e') dp[i][x] = (dp[i-1]['a'-'a'] + dp[i-1]['i'-'a']) % mod;
                if(j == 'i') dp[i][x] = (dp[i-1]['a'-'a'] + dp[i-1]['e'-'a'] + dp[i-1]['o'-'a'] + dp[i-1]['u'-'a']) % mod;
                if(j == 'o') dp[i][x] = (dp[i-1]['i'-'a'] + dp[i-1]['u'-'a']) % mod;
                if(j == 'u') dp[i][x] = dp[i-1]['a'-'a'] % mod;
            }
        }
        int ans = 0;
        for(char i : vowel) ans = (ans + dp[n][i-'a']) % mod;
        return ans;
    }
};