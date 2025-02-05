class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n),ans;
        int l = s.length();
        for(int i = l-1;i >= 0;i--){
            if(i > 0 && s[i] < s[i-1]){
                ans = string(ans.length()+1,'9');
                s[i-1] -= 1;
            }
            else ans += s[i];
        }
        reverse(ans.begin(),ans.end());
        return stoi(ans);
    }
};