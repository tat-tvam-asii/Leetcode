class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int m = __builtin_popcount(num1);
        while(m > n){
            num1 &= (num1 - 1);
            m--;
        }
        while(m < n){
            num1 |= (num1 + 1);
            m++;
        }
        return num1;
    }
};