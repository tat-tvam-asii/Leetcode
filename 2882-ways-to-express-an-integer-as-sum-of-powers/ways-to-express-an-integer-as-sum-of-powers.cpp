class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            long long nx = pow(i,x);
            for(int j = n;j >= nx;j--){
                if(j - nx >= 0) dp[j] = (dp[j] + dp[j-nx]) % 1000000007;
            }
        }
        return dp[n];
    }
};