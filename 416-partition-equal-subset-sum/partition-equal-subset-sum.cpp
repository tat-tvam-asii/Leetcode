class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;
        int n = nums.size(),s = sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(s+1));
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= s;j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= s;j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
    }
};