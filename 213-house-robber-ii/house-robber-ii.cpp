class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(),prev1 = nums[0],prev2 = 0;
        for(int i = 1;i < n-1;i++){
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        if(n < 2) return prev1;
        int temp = prev1;
        prev1 = nums[1];
        prev2 = 0;
        for(int i = 2;i < n;i++){
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(temp,prev1);
    }
};