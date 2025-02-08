class Solution {
public:
    int maxCount(vector<int>& banned, int n, int mxsum) {
        set<int> s;
        int cnt = 0;
        for(int i : banned) s.insert(i);
        for(int i = 1;i <= n;i++){
            if(!s.contains(i)){
                if(mxsum - i >= 0) mxsum -= i,cnt++;
                else return cnt;
            }
        }
        return cnt;
    }
};