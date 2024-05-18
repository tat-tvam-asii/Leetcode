class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int arr[26] = {0};
        for(int i = 0;i < s.length();i++) arr[s[i]-'a'] = i;
        int ans = 0;
        for(int i = 0;i < t.length();i++) ans += abs(arr[t[i]-'a'] - i);
        return ans;
    }
};