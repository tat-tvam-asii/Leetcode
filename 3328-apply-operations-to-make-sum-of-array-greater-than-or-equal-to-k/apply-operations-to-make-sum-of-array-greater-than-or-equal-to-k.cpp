class Solution {
public:
    int minOperations(int k) {
        if(k == 1) return 0;
        int mn = INT_MAX;
        for(int i = 1;i <= k/2;i++){
            int temp = (k + i - 1)/i;
            mn = min(mn,temp - 1 + i - 1);
        }
        return mn;
    }
};