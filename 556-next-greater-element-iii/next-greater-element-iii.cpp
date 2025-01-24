class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.length();
        int i = l - 2;
        while(i >= 0 && s[i] >= s[i+1]) i--;
        if(i == -1) return -1;
        reverse(s.begin() + i + 1,s.end());
        for(int j = i + 1;j < l;j++){
            if(s[j] > s[i]){
                swap(s[i],s[j]);
                break;
            }
        }
        long ans = stol(s);
        return ans > INT_MAX ? -1 : ans;
    }
};