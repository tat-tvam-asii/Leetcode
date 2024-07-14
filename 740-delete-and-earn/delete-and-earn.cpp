class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        vector<int> dp(1e4+1,0);
        int mx = *max_element(nums.begin(),nums.end());
        if(mp[1]) dp[1] = mp[1];
        for(int i = 2;i <= mx;i++){
            dp[i] = max(dp[i-1],mp[i]*i + dp[i-2]);
        }
        return dp[mx];
    }
};