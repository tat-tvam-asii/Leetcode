class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int cnt = 0,n = nums.size();
        for(int i = 0;i < n;i++){
            if(i+1 < n && nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        for(int i : nums){
            if(i == 0) cnt++;
            else ans.push_back(i);
        }
        while(cnt--) ans.push_back(0);
        return ans;
    }
};