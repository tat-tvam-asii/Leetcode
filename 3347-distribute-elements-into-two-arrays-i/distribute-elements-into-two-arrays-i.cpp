class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans,part1,part2;
        part1.push_back(nums[0]);
        part2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(part1.back() > part2.back()) part1.push_back(nums[i]);
            else part2.push_back(nums[i]);
        }
        ans = part1;
        for(int i : part2) ans.push_back(i);
        return ans;
    }
};