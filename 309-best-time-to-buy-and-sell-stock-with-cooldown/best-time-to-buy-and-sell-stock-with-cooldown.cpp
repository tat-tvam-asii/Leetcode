class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind = n-1;ind >= 0;ind--){
            for(int buy = 0;buy <= 1;buy++){
                int profit = 0;
                if(buy == 0){
                    profit = max(-prices[ind] + dp[ind+1][1],0 + dp[ind+1][0]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+2][0],0 + dp[ind+1][1]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][0];
    }
};