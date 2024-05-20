class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        unordered_map<double,int> mp;
        for(auto x : rectangles){
            double a = x[0],b = x[1];
            if(mp[a/b]) ans += mp[a/b];
            mp[a/b]++;
        }
        return ans;
    }
};