class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int mn = INT_MAX;
        for(int i = 0;i < nums.size();i++){
            int temp = 0;
            for(int j = i;j < nums.size();j++){
                temp |= nums[j];
                if(temp >= k){
                    mn = min(mn,j - i + 1);
                }
            }
        }
        if(mn == INT_MAX) return -1;
        return mn;
    }
};