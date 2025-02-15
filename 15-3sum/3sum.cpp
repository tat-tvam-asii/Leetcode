class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++){
            if(i && nums[i] == nums[i-1]) continue;
            int j = i+1,k = n-1,target = -nums[i];
            while(j < k){
                if(nums[j] + nums[k] == target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] < target) j++;
                else k--;
                while(j > i+1 && j < k && nums[j] == nums[j-1]) j++;
                while(k < n-1 && j < k && nums[k] == nums[k+1]) k--;
            }
        }
        return ans;
    }
};