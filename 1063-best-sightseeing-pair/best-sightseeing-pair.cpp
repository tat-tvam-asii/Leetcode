class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left = values[0],ans = INT_MIN;
        for(int i = 1;i < values.size();i++){
            ans = max(ans,left + values[i] - i);
            left = max(left,values[i] + i);
        }
        return ans;
    }
};