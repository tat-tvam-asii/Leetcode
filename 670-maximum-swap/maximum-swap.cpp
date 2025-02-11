class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int l = s.length();
        for(int i = 0;i < l;i++){
            char mx = s[i];
            int k;
            for(int j = i+1;j < l;j++){
                if(s[j] >= mx){
                    k = j;
                    mx = s[j];
                }
            }
            if(mx > s[i]){
                swap(s[i],s[k]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};