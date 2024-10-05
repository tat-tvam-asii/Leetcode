class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0,j = s.length() - 1;
        while(i <= j){
            if(s[i] != s[j]) break;
            i++;
            j--;
        }
        int i1 = i,i2 = i+1,j1 = j-1,j2 = j;
        bool flag = true;
        while(i1 <= j1){
            if(s[i1] != s[j1]){
                flag = false;
                break;
            }
            i1++;
            j1--;
        }
        if(flag) return true;
        while(i2 <= j2){
            if(s[i2] != s[j2]) return false;
            i2++;
            j2--;
        }
        return true;
    }
};