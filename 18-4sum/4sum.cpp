class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j = i+1;j < n;j++){
                int k = j+1,l = n-1;
                while(k < l){
                    long long total = nums[i]*1ll + nums[j] + nums[k] + nums[l];
                    if(total > target) l--;
                    else if(total < target) k++;
                    else{
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        while(nums[k] == nums[k-1] && k < l) k++;
                    }
                }
            }
        }
        for(auto i : s) res.push_back(i);
        return res;  
    }
};