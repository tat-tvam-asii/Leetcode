class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos = 0,ans = 0;
        for(int i : nums){
            pos += i;
            if(pos == 0) ans++;
        }
        return ans;
    }
};