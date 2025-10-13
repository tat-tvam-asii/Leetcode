class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0;i < n;i++){
            ans.push_back(words[i]);
            while(i != n-1){
                string s1 = words[i];
                string s2 = words[i+1];
                sort(s1.begin(),s1.end());
                sort(s2.begin(),s2.end());
                if(s1 == s2) i++;
                else break;
            }
        }
        return ans;
    }
};