class Solution {
public:
    long long solve(vector<int>& nums,int i,bool add,vector<vector<long long>>& dp){
        if(i == nums.size()) return 0;
        if(dp[add][i] != -1) return dp[add][i];
        int value = add ? nums[i] : -nums[i];
        return dp[add][i] = max(value + solve(nums,i+1,!add,dp),solve(nums,i+1,add,dp));
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(2,vector<long long>(nums.size(),-1));
        return solve(nums,0,true,dp);
    }
};