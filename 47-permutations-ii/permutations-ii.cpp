class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>>& ans,int i){
        if(i == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for(int j = i;j < nums.size();j++){
            if(j != i && nums[j] == nums[i]) continue;
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,ans,0);
        return ans;
    }
};