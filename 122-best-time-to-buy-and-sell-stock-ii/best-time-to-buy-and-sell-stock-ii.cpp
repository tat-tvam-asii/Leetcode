class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>>& dp,int ind,int buy){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(prices,dp,ind+1,0),0 + solve(prices,dp,ind+1,1));
        }
        else profit = max(prices[ind] + solve(prices,dp,ind+1,1),0 + solve(prices,dp,ind+1,0));
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,dp,0,1);
    }
};