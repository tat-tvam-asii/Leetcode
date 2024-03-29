class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0,cnt = 0;
        int mx = *max_element(nums.begin(),nums.end());
        for(int i = 0,j = 0;i < nums.size();i++){
            if(nums[i] == mx) cnt++;
            while(j <= i && cnt == k){
                ans += nums.size() - i;
                if(nums[j++] == mx) cnt--;
            }
        }
        return ans;
    }
};