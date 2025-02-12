class Solution {
public:
    int digit_sum(int n){
        if(n == 0) return 0;
        return n % 10 + digit_sum(n / 10);
    }

    int maximumSum(vector<int>& nums) {
        vector<priority_queue<int>> vpq(82);
        for(int n : nums){
            vpq[digit_sum(n)].push(n);
        }
        int mx = -1;
        for(auto pq : vpq){
            if(pq.size() < 2) continue;
            int a,b;
            a = pq.top(),pq.pop();
            b = pq.top();
            mx = max(mx,a + b);
        }
        return mx;
    }
};