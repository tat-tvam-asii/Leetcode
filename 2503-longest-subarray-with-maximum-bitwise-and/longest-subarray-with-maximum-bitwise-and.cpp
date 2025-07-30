class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mxlen = 1,templen = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == mx) templen++;
            else{
                mxlen = max(mxlen,templen);
                templen = 0;
            }
        }
        mxlen = max(mxlen,templen);
        return mxlen;
    }
};