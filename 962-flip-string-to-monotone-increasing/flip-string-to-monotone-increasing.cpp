class Solution {
public:

    int minFlipsMonoIncr(string s) {
        int i = 0,l = s.length();
        for(i = 0;i < l;i++){
            if(s[i] == '1') break;
        }
        int prev_one = 0,curr_one,prev_zero = 0,curr_zero;
        for(int i = l-1;i >= 0;i--){
            curr_one = (s[i] != '1') + prev_one;
            curr_zero = (s[i] == '1') + min(prev_zero,prev_one);
            prev_one = curr_one;
            prev_zero = curr_zero;
        }
        return min(curr_one,curr_zero);
    }
};