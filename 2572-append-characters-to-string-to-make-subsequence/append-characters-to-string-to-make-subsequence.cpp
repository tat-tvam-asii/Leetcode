class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0,j = 0;
        while(j < s.length()){
            if(s[j] == t[i]){
                i++;
            }
            j++;
        }
        return t.length()-i;
    }
};