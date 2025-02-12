class Solution {
public:
    int digit_sum(int n){
        if(n == 0) return 0;
        return n % 10 + digit_sum(n / 10);
    }

    int maximumSum(vector<int>& nums) {
        vector<vector<int>> vv(82);
        for(int n : nums){
            vv[digit_sum(n)].push_back(n);
        }
        int mx = -1;
        for(auto v : vv){
            if(v.size() < 2) continue;
            int mx1 = 0,mx2 = 0;
            for(int n : v){
                if(n > mx1){
                    mx2 = mx1;
                    mx1 = n;
                }
                else if(n > mx2) mx2 = n;
            }
            mx = max(mx,mx1 + mx2);
        }
        return mx;
    }
};