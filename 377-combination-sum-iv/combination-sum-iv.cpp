class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i <= target;i++){
            for(int j : nums) if(i-j >= 0) dp[i] += dp[i-j];
        }
        return dp[target];
    }
};