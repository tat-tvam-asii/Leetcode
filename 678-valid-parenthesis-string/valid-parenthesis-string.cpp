class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin--;
            if (c == '*')
                cmax++, cmin--;
            cmin = max(cmin,0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }
};