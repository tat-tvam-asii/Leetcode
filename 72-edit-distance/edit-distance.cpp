class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(),m = s2.length(),prev;
        vector<int> curr(m+1,0);
        for(int i = 0;i <= m;i++) curr[i] = i;
        for(int i = 1;i <= n;i++){
            prev = curr[0];
            curr[0] = i;
            for(int j = 1;j <= m;j++){
                int temp =  curr[j];
                if(s1[i-1] == s2[j-1]) curr[j] = prev;
                else curr[j] = 1 + min({curr[j],curr[j-1],prev});
                prev = temp;
            }
        }
        return curr[m];
    }
};