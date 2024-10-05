class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0,j = k-1;
        int mn = INT_MAX;
        while(j < nums.size()){
            mn = min(mn,nums[j] - nums[i]);
            j++;
            i++;
        }
        return mn;
    }
};