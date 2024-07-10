class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(),m = s2.length();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i = 0;i <= m;i++) prev[i] = i;
        for(int i = 1;i <= n;i++){
            curr[0] = i;
            for(int j = 1;j <= m;j++){
                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min({prev[j],prev[j-1],curr[j-1]});
            }
            prev = curr;
        }
        return prev[m];
    }
};