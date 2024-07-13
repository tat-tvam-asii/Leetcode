class Solution {
public:
    string expand(int left,int right,string& s){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        string mx = s.substr(0,1);
        for(int i = 0;i < s.length();i++){
            string odd = expand(i,i,s);
            string even = expand(i,i+1,s);
            if(odd.length() > mx.length()) mx = odd;
            if(even.length() > mx.length()) mx = even;
        }
        return mx;
    }
};