class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_set<int> faults;
        for(int i = 0;i < n-1;i++){
            if((nums[i] + nums[i+1]) % 2 == 0) faults.insert(i);
        }
        vector<bool> ans;
        for(auto i : queries){
            bool flag = true;
            for(int n : faults){
                if(n >= i[0] && n < i[1]){
                    flag = false;
                    ans.push_back(false);
                    break;
                }
            }
            if(flag) ans.push_back(true);
        }
        return ans;
    }
};