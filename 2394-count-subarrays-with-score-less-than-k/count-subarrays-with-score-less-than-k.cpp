class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0,i = 0,j = 0,n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
        pre.insert(pre.begin(),0);
        while(j < n){
            j++;
            while((pre[j] - pre[i])*(j-i) >= k){
                i++;
            }
            ans += j-i;
        }
        return ans;
    }
};