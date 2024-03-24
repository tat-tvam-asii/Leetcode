class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string,bool> mp;
        for(int i = 0;i < s.length()-1;i++){
            string temp = s.substr(i,2);
            mp[temp] = true;
            reverse(temp.begin(),temp.end());
            if(mp[temp]) return true;
        }
        return false;
    }
};