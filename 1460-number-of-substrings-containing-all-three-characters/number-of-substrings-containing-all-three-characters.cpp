class Solution {
public:
    int solve(string s){
        unordered_map<char,int> mp;
        int ans = 0;
        for(int j=0,i=0;j<s.length();j++){
            mp[s[j]]++;
            while(mp.size() > 2){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }

    int numberOfSubstrings(string s) {
        return s.length()*(s.length()+1)/2 - solve(s);
    }
};