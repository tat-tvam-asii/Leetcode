class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return 1;
        return 1ll*coloredCells(n-1) + 4*(n-1);
    }
};