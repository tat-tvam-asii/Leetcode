class Solution {
public:

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(2,vector<long long>(n+1,0));
        for(int i = n-1;i >= 0;i--){
            dp[0][i] = max(nums[i]+dp[1][i+1],dp[0][i+1]);
            dp[1][i] = max(-nums[i]+dp[0][i+1],dp[1][i+1]);
        }
        return max(dp[0][0],dp[1][0]);
    }
};