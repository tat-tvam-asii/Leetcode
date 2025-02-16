class Solution {
public:
    string reverseWords(string s) {
        while(s[0] == ' ') s.erase(s.begin());
        while(s[s.size() - 1] == ' ') s.erase(s.begin()+s.size()-1);
        reverse(s.begin(),s.end());
        int j = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
                while(i+1 < s.size() && s[i+1] == ' ') s.erase(s.begin()+i+1);
            }
        }
        reverse(s.begin()+j,s.end());
        return s;
    }
};