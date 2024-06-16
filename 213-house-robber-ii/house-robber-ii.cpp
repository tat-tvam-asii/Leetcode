class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[102];
        dp[0] = 0;
        dp[1] = nums[0];
        int n = nums.size();
        for(int i = 2;i < n;i++) dp[i] = max(nums[i-1] + dp[i-2],dp[i-1]);
        if(n < 2) return dp[n];
        int dp1[102];
        dp1[0] = 0;
        dp1[1] = nums[1];
        for(int i = 2;i < n;i++) dp1[i] = max(nums[i] + dp1[i-2],dp1[i-1]);
        return max(dp[n-1],dp1[n-1]);
    }
};