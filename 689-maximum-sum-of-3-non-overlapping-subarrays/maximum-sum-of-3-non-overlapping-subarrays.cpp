class Solution {
public:
    void dfs(vector<int>& ans,vector<int>& summ,vector<vector<int>>& dp,int ind,int cnt,int k){
        if(cnt == 0) return;
        if(ind >= summ.size()) return;

        int take = summ[ind] + solve(dp,summ,ind+k,cnt-1,k);
        int nottake = solve(dp,summ,ind+1,cnt,k);

        if(take >= nottake){
            ans.push_back(ind);
            dfs(ans,summ,dp,ind+k,cnt-1,k);
        }
        else dfs(ans,summ,dp,ind+1,cnt,k);
    }

    int solve(vector<vector<int>>& dp,vector<int>& summ,int ind,int cnt,int k){
        if(cnt == 0) return 0;
        if(ind >= summ.size()) return cnt > 0 ? INT_MIN : 0;
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        return dp[ind][cnt] = max(summ[ind] + solve(dp,summ,ind + k,cnt-1,k),solve(dp,summ,ind + 1,cnt,k));
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> summ(n,0);
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        summ[0] = windowSum;

        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            summ[i - k + 1] = windowSum;
        }
        vector<vector<int>> dp(n,vector<int>(4,-1));
        solve(dp,summ,0,3,k);
        vector<int> ans;
        dfs(ans,summ,dp,0,3,k);
        return ans;
    }
};