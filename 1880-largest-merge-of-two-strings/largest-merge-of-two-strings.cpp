class Solution {
public:
    string largestMerge(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        string ans;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(w1[i] - w2[j]> 0){
                ans.push_back(w1[i++]);
            }
            else if(w1[i] - w2[j]< 0){
                ans.push_back(w2[j++]);
            }
            else{
                string s1(begin(w1) + i, end(w1));
                string s2(begin(w2) + j, end(w2));
                if(s1 > s2) ans.push_back(w1[i++]);
                else ans.push_back(w2[j++]);
                }
            }
            

        while(i < n1) ans.push_back(w1[i++]);
        while(j < n2) ans.push_back(w2[j++]);

        return ans;
    }
};