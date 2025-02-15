class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> min_arr(n);
        min_arr[0] = nums[0];
        for(int i = 1;i < n;i++) min_arr[i] = min(min_arr[i-1],nums[i]);
        for(int i = n-1;i >= 0;i--){
            if(nums[i] <= min_arr[i]) continue;
            while(!st.empty() && st.top() <= min_arr[i]) st.pop();
            if(!st.empty() && st.top() < nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
    }
};