class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0,ans = 0,i = 0,j = 0,n = nums.size();
        while(j < n){
            sum += nums[j];
            while(i <= j && sum*(j-i+1) >= k){
                sum -= nums[i++];
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};