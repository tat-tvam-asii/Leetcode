class Solution {
public:
    int mod = 1e9 + 7;

    long long solve(int n,char i,vector<vector<int>>& dp){
        if(n == 1) return 1;
        int x = i - 'a';
        if(dp[n][x] != -1) return dp[n][x];
        if(i == 'a') return dp[n][x] = solve(n-1,'e',dp) % mod;
        if(i == 'e') return dp[n][x] = (solve(n-1,'a',dp) + solve(n-1,'i',dp)) % mod;
        if(i == 'i') return dp[n][x] = (solve(n-1,'a',dp) + solve(n-1,'e',dp) + solve(n-1,'u',dp) + solve(n-1,'o',dp)) % mod;
        if(i == 'o') return dp[n][x] = (solve(n-1,'i',dp) + solve(n-1,'u',dp)) % mod;
        if(i == 'u') return dp[n][x] = solve(n-1,'a',dp) % mod;
        return 0;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(26,-1));
        return (solve(n,'a',dp) + solve(n,'e',dp) + solve(n,'i',dp) + solve(n,'o',dp) + solve(n,'u',dp)) % mod;
    }
};