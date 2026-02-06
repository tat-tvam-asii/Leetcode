class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),i = 0,j = 0,mx = 0;
        while(i < n && j < n){
            if(nums[j] <= 1ll*k*nums[i]) j++;
            else{
                mx = max(mx,j-i);
                i++;
            }
        }
        mx = max(mx,j-i);
        return n - mx;
    }
};