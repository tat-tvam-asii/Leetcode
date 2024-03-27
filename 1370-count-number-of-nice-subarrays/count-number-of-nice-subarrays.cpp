class Solution {
public:
    int atMost(vector<int> nums,int k){
        int ans = 0,cnt = 0,i = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2) cnt++;
            while(cnt > k){
                if(nums[i++]%2) cnt--;
            }
            ans += j - i + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};