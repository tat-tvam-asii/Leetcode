class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> lastmax(n);
        lastmax[n-1] = values[n-1] - (n-1);
        for(int i = n-2;i >= 0;i--) lastmax[i] = max(lastmax[i+1],values[i] - i);
        int mx = INT_MIN;
        for(int i = 0;i < n-1;i++) mx = max(mx,values[i] + i + lastmax[i+1]);
        return mx;
    }
};