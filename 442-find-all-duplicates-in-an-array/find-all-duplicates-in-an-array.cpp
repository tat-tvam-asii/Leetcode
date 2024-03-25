class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int& i : nums){
            nums[(i-1)%n] += n; 
        }
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 2*n) ans.push_back(i+1);
        }
        return ans;
    }
};