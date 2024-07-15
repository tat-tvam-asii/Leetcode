class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = n;j >= 1;j--){
                long long nx = pow(i,x);
                if(j - nx >= 0) dp[j] = (dp[j] + dp[j-nx]) % 1000000007;
            }
        }
        return dp[n];
    }
};