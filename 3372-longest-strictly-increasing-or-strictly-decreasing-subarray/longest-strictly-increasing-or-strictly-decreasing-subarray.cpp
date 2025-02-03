class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mxinc = 1,cnt = 1,mxdec = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[i-1]) cnt++;
            else{
                mxinc = max(mxinc,cnt);
                cnt = 1;
            }
        }
        mxinc = max(mxinc,cnt);
        cnt = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < nums[i-1]) cnt++;
            else{
                mxdec = max(mxdec,cnt);
                cnt = 1;
            }
        }
        mxdec = max(mxdec,cnt);
        return max(mxinc,mxdec);
    }
};
