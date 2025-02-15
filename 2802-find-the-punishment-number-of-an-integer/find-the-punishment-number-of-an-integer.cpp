class Solution {
public:
    bool check(int n,int target){
        if(target < 0 || n < target) return false;
        if(n == target) return true;
        return check(n / 10,target - n % 10) || check(n / 100, target - n % 100) || check(n / 1000, target - n % 1000);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(check(i*i,i)) ans += i*i;
        }
        return ans;
    }
};