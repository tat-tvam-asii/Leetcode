class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int temp = kthGrammar(n-1,(k+1)/2);
        if(temp == 0) return (k+1)%2;
        else return k%2;
    }
};