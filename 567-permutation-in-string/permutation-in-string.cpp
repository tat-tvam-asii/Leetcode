class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0,j = 0,l = s1.length();
        vector<int> cnt(26,0);
        for(char c : s1) cnt[c-'a']++;
        for(j = 0;j < s2.length();j++){
            cnt[s2[j] - 'a']--;
            if(j - i + 1 > l) cnt[s2[i++] - 'a']++;
            bool flag = true;
            for(int k = 0;k < 26;k++){
                if(cnt[k]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};