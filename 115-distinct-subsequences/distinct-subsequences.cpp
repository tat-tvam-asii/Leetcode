class Solution {
public:
    
    int numDistinct(string s, string t) {
        int m = s.length(),n = t.length();
        vector<unsigned long long> prev(n+1,0),curr(n+1,0);
        prev[n] = curr[n] = 1;
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                curr[j] = prev[j];
                if(s[i] == t[j]) curr[j] += prev[j+1];
            }
            prev = curr;
        }
        return prev[0];
    }
};