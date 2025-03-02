class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(auto i : nums1) mp[i[0]] = i[1];
        for(auto i : nums2){
            if(mp[i[0]]) mp[i[0]] += i[1];
            else mp[i[0]] = i[1];
        }
        vector<vector<int>> ans;
        for(auto&[a,b] : mp) ans.push_back({a,b});
        return ans;
    }
};