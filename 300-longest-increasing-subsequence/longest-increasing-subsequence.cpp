class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]) length[i] = max(length[i],length[j]+1);
            }
        }
        return *max_element(length.begin(),length.end());
    }
};