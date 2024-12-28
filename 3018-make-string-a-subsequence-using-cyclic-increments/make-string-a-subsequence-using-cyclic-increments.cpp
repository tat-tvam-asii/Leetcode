class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l1 = str1.length(),l2 = str2.length();
        int i = 0,j = 0;
        while(i < l1 && j < l2){
            if((str2[j] - str1[i] + 26) % 26 <= 1) j++;
            i++;
        }
        return j == l2;
    }
};