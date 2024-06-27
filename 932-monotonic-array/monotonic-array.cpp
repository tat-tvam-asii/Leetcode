class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(),temp = 1,temp1 = 1;
        for(int i = 1;i < n;i++){
            if(nums[i] >= nums[i-1]) temp++;
            if(nums[i] <= nums[i-1]) temp1++;
        }
        return (temp == n || temp1 == n);
    }
};