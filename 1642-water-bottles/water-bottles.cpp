class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot = numBottles,rem = 0;
        while(numBottles >= numExchange){
            int q = numBottles / numExchange;
            int rem = numBottles - numExchange*q;
            tot += q;
            numBottles = rem + q;
        }
        return tot;
    }
};