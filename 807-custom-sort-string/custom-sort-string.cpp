class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26] = {0};
        for(int i=0;i<order.length();i++) arr[order[i]-'a'] = i;
        sort(s.begin(),s.end(),[arr](char a,char b) -> bool{
            return arr[a-'a'] < arr[b-'a'];
        });
        return s;
    }
};