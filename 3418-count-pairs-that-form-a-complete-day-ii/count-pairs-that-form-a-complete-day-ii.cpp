class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int,int> mp;
        for(int n : hours){
            ans += mp[(24 - n % 24) % 24];
            mp[n % 24]++;
        }
        return ans;
    }
};