class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0),bitpos(31,-1);
        for(int i = n-1;i >= 0;i--){
            int temp = nums[i],pos = 0;
            while(temp){
                if(temp & 1) bitpos[pos] = i;
                pos++;
                temp >>= 1;
            }
            int mx = i;
            for(int n : bitpos) mx = max(mx,n);
            ans[i] = mx - i + 1;
        }
        return ans;
    }
};