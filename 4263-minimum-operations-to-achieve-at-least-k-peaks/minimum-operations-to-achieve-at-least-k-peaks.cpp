class Solution {
public:
    inline static int dp[5005][2510];

    long solve(vector<int>& nums,int ind,int r,int n,int k){
        if(k == 0) return 0;
        if(ind >= r) return INT_MAX;
        if(dp[ind][k] != -1) return dp[ind][k];
        int x = nums[(ind-1+n)%n];
        int y = nums[(ind+1)%n];
        int inc = max({x,y,(nums[ind]-1)}) + 1 - nums[ind];
        return dp[ind][k] = min((inc + solve(nums,ind+2,r,n,k-1)),solve(nums,ind+1,r,n,k));
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n/2) return -1;
        for(int i = 0;i <= n+1;i++){
            for(int j = 0;j <= n/2+1;j++){
                dp[i][j] = -1;
            }
        }
        long ans1 = solve(nums,0,n-1,n,k);
        for(int i = 0;i <= n+1;i++){
            for(int j = 0;j <= n/2+1;j++){
                dp[i][j] = -1;
            }
        }
        long ans2 = solve(nums,1,n,n,k);
        long ans = min(ans1,ans2);
        if(ans == INT_MAX) return -1;
        return (int)ans;
    }
};