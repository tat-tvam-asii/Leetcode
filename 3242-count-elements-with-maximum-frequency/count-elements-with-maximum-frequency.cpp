class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        int mx = 0,ans = 0;
        for(auto i:mp){
            mx = max(mx,i.second);
        }
        for(auto i:mp){
            if(i.second == mx) ans += i.second;
        }
        return ans;
    }
};