class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end(),greater<int>());
        vector<pair<int,int>> vp;
        int n = difficulty.size(),m = worker.size();
        for(int i = 0;i < n;i++){
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end(),[](auto& left,auto& right){
            return left.second > right.second;
        });
        int i = 0,j = 0,ans = 0;
        while(j < m){
            while(i < n && vp[i].first > worker[j]) i++;
            if(i < n) ans += vp[i].second;
            j++;
        }
        return ans;
    }
};