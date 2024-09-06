class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long> pre(n+1);
        pre[0] = 0;
        for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + nums[i-1];
        int i = 0,j = 1,mx = 1;
        while(j < n){
            while(j < n-1 && nums[j] == nums[j+1]) j++;
            long long rem = 1ll*nums[j]*(j - i + 1) - (pre[j+1] - pre[i]);
            while(rem > k && i < j){
                rem -= (nums[j] - nums[i++]);
            }
            if(rem <= k) mx = max(mx,j - i + 1);
            j++;
        }
        return mx;
    }
};