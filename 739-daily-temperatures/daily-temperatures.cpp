class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> ngr;
        for(int i = n-1;i >= 0;i--){
            while(!ngr.empty() && temperatures[ngr.top()] <= temperatures[i]) ngr.pop();
            if(ngr.empty()) ans[i] = 0;
            else ans[i] = ngr.top() - i;
            ngr.push(i);
        }
        return ans;
    }
};