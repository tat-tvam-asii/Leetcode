class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mxsum = 0,sum = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] <= nums[i-1]){
                mxsum = max(mxsum,sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(mxsum,sum);
    }
};