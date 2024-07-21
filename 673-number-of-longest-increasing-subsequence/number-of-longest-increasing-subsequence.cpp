class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n,1),num(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]) length[i] = max(length[i],length[j]+1);
            }
            for(int j = 0;j < i;j++){
                if(length[j] == length[i]-1 && nums[j] < nums[i]) num[i] += num[j];
            }
            num[i] = max(num[i],1);
        }
        int mx = *max_element(length.begin(),length.end());
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(length[i] == mx) ans += num[i];
        }
        return ans;
    }
};