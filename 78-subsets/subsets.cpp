class Solution {
public:
    void solve(vector<int> nums,vector<int> temp,set<vector<int>>& ans){
        if(nums.size() == 0) return;
        vector<int> temp1,temp2;
        temp1 = temp;
        temp2 = temp;
        temp2.push_back(nums.front());
        nums.erase(nums.begin());
        ans.insert(temp1);
        ans.insert(temp2);
        solve(nums,temp1,ans);
        solve(nums,temp2,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        solve(nums,temp,ans);
        vector<vector<int>> ans1;
        for(auto i : ans) ans1.push_back(i);
        return ans1;
    }
};