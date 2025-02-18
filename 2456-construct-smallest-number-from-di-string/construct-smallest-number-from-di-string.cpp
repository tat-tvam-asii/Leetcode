class Solution {
public:
    bool solve(string& pattern,vector<int>& isUsed,string& temp){
        int n = pattern.size();
        if(temp.size() == n+1){
            for(int i = 1;i <= n;i++){
                if(pattern[i-1] == 'I' && temp[i] <= temp[i-1]) return false;
                if(pattern[i-1] == 'D' && temp[i] >= temp[i-1]) return false;
            }
            return true;
        }
        for(int i = 1;i <= n+1;i++){
            if(isUsed[i]) continue;
            isUsed[i] = 1;
            temp.push_back('0' + i);
            if(solve(pattern,isUsed,temp)) return true;
            temp.pop_back();
            isUsed[i] = 0;
        }
        return false;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> isUsed(n+2,0);
        string temp = "";
        if(solve(pattern,isUsed,temp)) return temp;
        return "";
    }
};