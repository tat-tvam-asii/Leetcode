class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        int p = 1,pp;
        for(int i = l-1;i >= 0;i--){
            int cur = s[i] == '0' ? 0 : p;
            if(i < l-1 && (s[i] == '1' || s[i] == '2'&&s[i+1] < '7')) cur += pp;
            pp = p;
            p = cur;
        }
        return p;
    }
};