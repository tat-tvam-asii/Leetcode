class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> next(n,-1);
        for(int i = n-2;i >= 0;i--){
            if(nums2[i+1] > nums2[i]) next[i] = nums2[i+1];
            else{
                int j = i+1;
                while(j < n-1 && next[j] < nums2[i]) j++;
                next[i] = next[j];
            }
        }
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++) mp[nums2[i]] = i;
        vector<int> ans;
        for(int i : nums1) ans.push_back(next[mp[i]]);
        return ans; 
    }
};