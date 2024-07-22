class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= min(k,i);j++){
                if(i - j >= 0) dp[i] = max(dp[i],(dp[i-j] + *max_element(arr.begin()+i-j,arr.begin()+i)*j));
            }
        }
        return dp[n];
    }
};