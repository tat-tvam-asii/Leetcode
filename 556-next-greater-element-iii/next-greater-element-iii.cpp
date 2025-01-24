class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.length();
        for(int i = l-2;i >= 0;i--){
            char c = '@';
            int ind = i;
            for(int j = i+1;j < l;j++){
                if(s[j] > s[i]){
                    if(s[j] < c){
                        c = s[j];
                        ind = j;
                    }
                }
            }
            if(c != '@'){
                swap(s[i],s[ind]);
                sort(s.begin()+i+1,s.end());
                long int i = stol(s);
                if(i > INT_MAX) return -1;
                return stoi(s);
            }
        }
        return -1;
    }
};