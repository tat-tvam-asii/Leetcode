class Solution {
public:
    int solve(vector<int>& nums,int target,int ind,int x,vector<vector<int>>& dp){
        if(dp[ind][x] != -1) return dp[ind][x];
        if(ind == nums.size()){
            if(x == target) return dp[ind][x] = 0;
            else return dp[ind][x] = nums.size() + 1;
        }
        return dp[ind][x] = min(solve(nums,target,ind+1,x^nums[ind],dp),1 + solve(nums,target,ind+1,x,dp));
    }

    int minRemovals(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(16385,-1));
        int ans = solve(nums,target,0,0,dp);
        if(ans == nums.size() + 1) return -1;
        return ans;
    }
};