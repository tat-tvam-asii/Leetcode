class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1),pos(31,-1);
        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j < 31;j++){
                if(nums[i] & (1 << j)) pos[j] = i;
                ans[i] = max(ans[i],pos[j] - i + 1);
            }
        }
        return ans;
    }
};