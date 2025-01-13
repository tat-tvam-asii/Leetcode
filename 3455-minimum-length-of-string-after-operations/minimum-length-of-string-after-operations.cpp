class Solution {
public:
    int minimumLength(string s) {
        int l = s.length();
        vector<int> cnt(26,0);
        for(char c : s){
            cnt[c-'a']++;
        }
        for(int i : cnt){
            if(i % 2) l -= (i - 1);
            else if(i) l -= (i - 2);
        }
        return l;
    }
};