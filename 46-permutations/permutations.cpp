class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,unordered_map<int,int>& mp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(mp[nums[i]]) continue;
            else{
                temp.push_back(nums[i]);
                mp[nums[i]]++;
            }
            solve(nums,temp,ans,mp);
            temp.pop_back();
            mp.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_map<int,int> mp;
        solve(nums,temp,ans,mp);
        return ans;
    }
};