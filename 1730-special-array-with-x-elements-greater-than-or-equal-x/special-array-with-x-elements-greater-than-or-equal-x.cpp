class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            int x = nums.size() - i;
            if(nums[i] >= x){
                if(i){
                    if(nums[i-1] < x) return x;
                }
                else return x;
            }
        }
        return -1;
    }
};