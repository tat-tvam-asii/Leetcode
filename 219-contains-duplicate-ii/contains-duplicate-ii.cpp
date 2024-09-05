class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0,j = 0,n = nums.size();
        while(j < n){
            if(mp[nums[j]]) return true;
            mp[nums[j]]++;
            j++;
            if(j - i > k){
                mp[nums[i]]--;
                i++;
            }
        }
        return false;
    }
};