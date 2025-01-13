class Solution {
public:
    int minimumLength(string s) {
        int l = s.length();
        vector<int> cnt(26,0);
        for(char c : s){
            cnt[c-'a']++;
        }
        for(int i : cnt){
            while(i >= 3){
                i -= 2;
                l -= 2;
            }
        }
        return l;
    }
};