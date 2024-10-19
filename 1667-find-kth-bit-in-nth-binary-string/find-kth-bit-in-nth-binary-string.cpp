class Solution {
public:
    string binaryString(int n){
        if(n == 1) return "0";
        string s0,s1;
        s0 = binaryString(n-1);
        s1 = s0 + "1";
        for(char& c : s0){
            if(c == '0') c = '1';
            else c = '0';
        }
        reverse(s0.begin(),s0.end());
        s1 += s0;
        return s1;
    }

    char findKthBit(int n, int k) {
        string s = binaryString(n);
        return s[k-1];
    }
};