class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int n = temp.size();
        vector<long long> pre(n);
        pre[0] = temp[0];
        for(int i = 1;i < n;i++) pre[i] = temp[i] + pre[i-1];
        long long ans = 0,sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
            if(sum == pre[i]) ans++;
        }
        return ans;
    }
};