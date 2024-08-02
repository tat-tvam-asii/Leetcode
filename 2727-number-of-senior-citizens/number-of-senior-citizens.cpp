class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string s : details){
            string temp = s.substr(11,2);
            if(stoi(temp) > 60) ans++;
        }
        return ans;
    }
};