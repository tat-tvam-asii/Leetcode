class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        vector<vector<bool>> dp(l,vector<bool>(l,false));
        int mxlen = 1,start = 0,end = 0;
        for(int i = 0;i < l;i++){
            dp[i][i] = true;
            for(int j = 0;j < i;j++){
                if(s[j] == s[i] && (i-j <= 2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(i-j+1 > mxlen){
                        mxlen = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};