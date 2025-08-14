class Solution {
public:
    int maxProfit(int limit,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(limit+1,0)),prev(2,vector<int>(limit+1,0));
        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j <= 1;j++){
                for(int k = limit;k > 0;k--){
                    if(j) curr[j][k] = max(-prices[i] + prev[0][k],0 + prev[1][k]);
                    else curr[j][k] = max(prices[i] + prev[1][k-1],0 + prev[0][k]);
                }
            }
            prev = curr;
        }
        return curr[1][limit];
    }
};