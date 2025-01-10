class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        vector<int> ans;
        for(auto&[a,b] : mp) if(b > nums.size()/3) ans.push_back(a);
        return ans;
    }
};