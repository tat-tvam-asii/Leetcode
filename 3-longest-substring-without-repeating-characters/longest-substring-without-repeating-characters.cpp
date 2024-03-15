class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0,mxlen=0;
        while(j < s.length()){
            mp[s[j]]++;
            if(mp.size() == j - i + 1){
                mxlen = max(mxlen,j - i + 1);
            }
            while(mp.size() < j - i + 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return mxlen;
    }
};