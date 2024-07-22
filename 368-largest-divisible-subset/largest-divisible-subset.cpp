class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),mx = 1;
        vector<int> dp(n,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) dp[i] = max(dp[i],dp[j] + 1);
            }
            mx = max(mx,dp[i]);
        }
        int num = 1;
        vector<int> ans;
        for(int i = n-1;i >= 0;i--){
            if(dp[i] == mx && (nums[i] % num == 0 || num % nums[i] == 0)){
                ans.push_back(nums[i]);
                mx--;
                num = nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};