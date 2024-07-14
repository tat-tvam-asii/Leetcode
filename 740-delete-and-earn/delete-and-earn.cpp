class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        int dp = 0,dp1 = 0,dp2 = 0;
        int mx = *max_element(nums.begin(),nums.end());
        if(mp[1]) dp1 = mp[1];
        for(int i = 2;i <= mx;i++){
            dp = max(dp1,mp[i]*i + dp2);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};