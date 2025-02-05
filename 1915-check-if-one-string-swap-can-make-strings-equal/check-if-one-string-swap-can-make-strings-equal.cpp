class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        string t1,t2;
        for(int i = 0;i < s1.length();i++) if(s1[i] != s2[i]) cnt++,t1 += s1[i],t2 += s2[i];
        reverse(t2.begin(),t2.end());
        return t1 == t2 && (cnt == 0 || cnt == 2);
    }
};