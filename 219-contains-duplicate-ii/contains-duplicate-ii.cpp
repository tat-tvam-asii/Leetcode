class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0,j = 0,n = nums.size();
        while(j < n){
            while(mp[nums[j]] && i < j){
                if(nums[i] == nums[j] && j - i <= k) return true;
                else i++;
            }
            mp[nums[j]]++;
            j++;
        }
        return false;
    }
};