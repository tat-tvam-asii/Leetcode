class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx = 0;
        unordered_map<char,int> mp;
        int i = 0,j = 0;
        while(j < s.length()){
            mp[s[j]]++;
            while(mp[s[j]] > 2){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            mx = max(mx,j - i + 1);
            j++;
        }
        return mx;
    }
};