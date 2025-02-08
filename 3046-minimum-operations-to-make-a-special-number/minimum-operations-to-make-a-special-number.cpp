class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ans = n;
        for(char c : num) if(c == '0') ans = n-1;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int temp = 10 * (num[i] - '0') + (num[j] - '0');
                if(temp % 25 == 0) ans = min(ans,n - i - 2);
            }
        }
        return ans;
    }
};