class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        reverse(nums.begin()+i+1,nums.end());
        if(i == -1) return;
        for(int j = i+1;j < n;j++){
            if(nums[j] > nums[i]){
                swap(nums[i],nums[j]);
                break;
            }
        }
    }
};