class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;
        int t1 = 0,t2 = 1,t3 = 1,t = 0;
        for(int i = 3;i <= n;i++){
            t = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = t;
        }
        return t3;
    }
};