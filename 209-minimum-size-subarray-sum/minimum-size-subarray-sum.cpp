class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0,i = 0,mn = 100001;
        for(int j = 0;j < nums.size();j++){
            sum += nums[j];
            if(sum >= target) mn = min(mn,j - i + 1);
            while(sum - nums[i] >= target && i < j){
                sum -= nums[i++];
                mn = min(mn,j - i + 1);
            }
        }
        if(mn == 100001) return 0;
        return mn;
    }
};