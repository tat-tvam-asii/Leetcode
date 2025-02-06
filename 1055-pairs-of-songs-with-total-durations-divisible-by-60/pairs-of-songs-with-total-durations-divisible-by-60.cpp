class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0,n = time.size();
        unordered_map<int,int> mp;
        mp[time[0]%60]++;
        for(int i = 1;i < n;i++){
            ans += mp[(60 - time[i]%60)%60];
            mp[time[i]%60]++;
        }
        return ans;
    }
};