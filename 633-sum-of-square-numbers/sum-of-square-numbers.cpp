class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0,b = sqrt(c);
        while(a <= b){
            int sum = c - a*a - b*b;
            if(sum > 0) a++;
            else if(sum < 0) b--;
            else return true;
        }
        return false;
    }
};