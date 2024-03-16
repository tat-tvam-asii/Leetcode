class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char i : t) mp[i]++;
        int i = 0,j = 0,start = 0,minlen = INT_MAX,count = mp.size();
        while(j < s.length()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            while(count == 0){
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) count++;
                    if(j-i+1 < minlen){
                        minlen = j-i+1;
                        start = i;
                    }
                }
                i++;
            }
            j++;
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start,minlen);
    }
};