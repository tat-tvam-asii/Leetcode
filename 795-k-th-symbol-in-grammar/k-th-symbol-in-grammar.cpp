class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            if(k%2) return 0;
            else return 1;
        }
        int temp = kthGrammar(n-1,(k+1)/2);
        if(temp == 0){
            if(k%2) return 0;
            else return 1;
        }
        else{
            if(k%2) return 1;
            else return 0;
        }
    }
};