class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() % 2) return false;
        int cmin = 0, cmax = 0;
        for (int i = 0;i < s.length();i++) {
            if(locked[i] == '0') cmax++,cmin--;
            else{
                if(s[i] == '(') cmax++,cmin++;
                else cmax--,cmin--;
            }
            cmin = max(cmin,0);
            if (cmax < 0) return false;
        }
        if(cmin > 0) return false;
        return cmax % 2 == 0;
    }
};