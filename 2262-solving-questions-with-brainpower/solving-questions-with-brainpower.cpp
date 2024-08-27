class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1,0);
        for(int i = n-1;i >= 0;i--){
            int temp = i + questions[i][1] + 1;
            if(temp > n) temp = n;
            dp[i] = max(questions[i][0] + dp[temp],dp[i+1]);
        }
        return dp[0];
    }
};