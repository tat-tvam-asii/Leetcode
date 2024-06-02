class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((target + sum) % 2) return 0;
        int s = (target + sum) / 2,n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(s+1,0));
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= s;j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
    }
};