class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2) return 0;
        int ans = 0,i = 0,j = 0,pro = 1;
        while(j < nums.size()){
            pro *= nums[j];
            while(i <=j && pro >= k){
                pro /= nums[i++];
            }
            if(i <= j) ans += j-i+1;
            j++;
        }
        return ans;
    }
};