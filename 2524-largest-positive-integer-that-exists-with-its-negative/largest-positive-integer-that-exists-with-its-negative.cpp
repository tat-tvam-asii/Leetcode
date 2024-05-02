class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        for(int i : nums){
            if(mp[-i]) return i;
        }
        return -1;
    }
};