class Solution {
public:
    int maxScore(string s) {
        int l = s.length();
        vector<int> zero(l,0),ones(l,0);
        zero[0] = (s[0] == '0');
        ones[0] = (s[0] == '1');
        for(int i = 1;i < l;i++){
            zero[i] = zero[i-1] + (s[i] == '0');
            ones[i] = ones[i-1] + (s[i] == '1');
        }
        int mx = 0;
        for(int i = 1;i < l;i++){
            mx = max(mx,zero[i-1] + (ones[l-1] - ones[i-1]));
        }
        return mx;
    }
};