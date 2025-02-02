class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        set<int> s;
        for(int i = 0;i < n-1;i++){
            if((nums[i] + nums[i+1]) % 2 == 0) s.insert(i);
        }
        vector<bool> ans;
        for(auto i : queries){
            if(s.lower_bound(i[0]) == s.lower_bound(i[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};