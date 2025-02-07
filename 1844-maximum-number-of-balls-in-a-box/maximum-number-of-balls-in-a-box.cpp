class Solution {
public:
    int digitsum(int n){
        if(n == 0) return 0;
        return n % 10 + digitsum(n/10);
    }

    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;
        for(int i = lowLimit;i <= highLimit;i++){
            mp[digitsum(i)]++;
        }
        int mx = 0;
        for(auto it : mp) mx = max(mx,it.second);
        return mx;
    }
};