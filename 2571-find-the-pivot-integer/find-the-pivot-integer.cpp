class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            if(i*(i+1) - i == n*(n+1)/2) return i;
        }
        return -1;
    }
};