class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        int mx = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) dp[i] = max(dp[i],dp[j] + 1);
            }
            mx = max(mx,dp[i]);
        }
        int temp = mx,temp1 = 1;
        vector<int> ans;
        for(int i = n-1;i >= 0;i--){
            if(dp[i] == temp && (nums[i] % temp1 == 0 || temp1 % nums[i] == 0)){
                ans.push_back(nums[i]);
                temp--;
                temp1 = nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};