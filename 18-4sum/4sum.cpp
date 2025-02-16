class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for(int j = i+1;j < n;j++){
                int k = j+1,l = n-1;
                while(k < l){
                    long long total = nums[i]*1ll + nums[j] + nums[k] + nums[l];
                    if(total > target) l--;
                    else if(total < target) k++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        while(nums[k] == nums[k-1] && k < l) k++;
                    }
                }
                while(j < n-1 && nums[j] == nums[j+1]) j++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;  
    }
};