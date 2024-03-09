class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i : nums) pq.push(i);
        while(pq.top() < k){
            int mn1 = pq.top();
            pq.pop();
            int mn2 = pq.top();
            pq.pop();
            long long tmp = 2*1ll*mn1 + mn2;
            if(tmp > k) tmp = k;
            pq.emplace(tmp);
            cnt++;
        }
        return cnt;
    }
};