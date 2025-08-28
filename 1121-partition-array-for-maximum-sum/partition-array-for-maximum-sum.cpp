class Solution {
public:
    int solve(vector<int>& arr,int i,int j,int k,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mx = INT_MIN,mxsum = 0;
        for(int t = i;t < i+k && t < arr.size();t++){
            mx = max(mx,arr[t]);
            int sum = (t-i+1) * mx + solve(arr,t+1,j,k,dp);
            mxsum = max(mxsum,sum);
        }
        return dp[i][j] = mxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n,k,dp);
    }
};