class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        vector<bool> dp(n,false);
        dp[0] = (nums[0] != 0);
        for(int i = 0;i < n;i++){
            if(!dp[i]) continue;
            for(int j = i+1;j <= min(n-1,i+nums[i]);j++){
                dp[j] = true;
            }
        }
        return dp[n-1];
    }
};