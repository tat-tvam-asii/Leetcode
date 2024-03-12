class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        for(int i=n-1;i>=n-k;i--){
            happiness[i] -= (n-1-i);
            sum += max(happiness[i],0);
        }
        return sum;
    }
};