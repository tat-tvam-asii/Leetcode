class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> length1(n,1);
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]) length1[i] = max(length1[i],length1[j]+1);
            }
        }
        
        int mx = 0;
        vector<int> length2(n,1);
        for(int i = n-2;i >= 0;i--){
            for(int j = n-1;j > i;j--){
                if(nums[j] < nums[i]) length2[i] = max(length2[i],length2[j]+1);
            }
            if(length1[i] > 1 && length2[i] > 1) mx = max(mx,length1[i] + length2[i] - 1);
        }

        return n - mx;
    }
};