class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum = 0,cnt = 0;
        unordered_map<int,int> mp;
        for(int n : nums){
            if(!mp[n] && n <= k+cnt) sum -= n,cnt++;
            mp[n] = true;
        }
        return sum + 1ll*(k+cnt)*(k+cnt+1)/2;
    }
};