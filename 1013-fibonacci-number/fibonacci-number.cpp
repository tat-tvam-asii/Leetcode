class Solution {
public:
    int fib(int n) {
        if(!n) return 0;
        int fib = 0,fib1 = 1,fib2 = 0;
        for(int i = 2;i <= n;i++){
            fib = fib1 + fib2;
            swap(fib1,fib2);
            swap(fib,fib1);
        }
        return fib1;
    }
};