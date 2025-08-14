class Solution {
public:
    int solve(vector<int>& prices,vector<vector<vector<int>>>& dp,int ind,int buy,int limit){
        if(limit == 0 || ind == prices.size()) return 0;
        if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(prices,dp,ind+1,0,limit),0 + solve(prices,dp,ind+1,1,limit));
        }
        else profit = max(prices[ind] + solve(prices,dp,ind+1,1,limit-1),0 + solve(prices,dp,ind+1,0,limit));
        return dp[ind][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,dp,0,1,2);
    }
};