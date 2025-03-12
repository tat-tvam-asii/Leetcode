class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0,h = nums.size() - 1,mx,mn;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] < 0) l = mid + 1;
            else h = mid - 1;
        }
        mn = h;
        l = 0,h = nums.size() - 1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] <= 0) l = mid + 1;
            else h = mid - 1;
        }
        mx = nums.size() - l - 1;
        return max(mx,mn) + 1;
    }
};