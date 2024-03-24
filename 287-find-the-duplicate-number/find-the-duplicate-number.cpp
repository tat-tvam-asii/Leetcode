class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])] < 0){
                ans = abs(nums[i]);
                break;
            }
            nums[abs(nums[i])] *= -1;
        }
        for(int& i : nums) if(i < 0) i *= -1;
        return ans;
    }
};