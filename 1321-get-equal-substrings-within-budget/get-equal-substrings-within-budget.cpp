class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0,cost = 0,mxlen = 0;
        for(int j = 0;j < s.length();j++){
            cost += abs(s[j] - t[j]);
            while(cost > maxCost){
                cost -= abs(s[i] - t[i]);
                i++;
            }
            if(j - i + 1 > mxlen) mxlen = j - i + 1;
        }
        return mxlen;
    }
};