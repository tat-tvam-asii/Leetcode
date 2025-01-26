class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ngl(n);
        stack<int> stgl;
        for(int i = 0;i < n;i++){
            while(!stgl.empty() && stgl.top() <= height[i]) stgl.pop();
            if(stgl.empty()){
                ngl[i] = 0;
                stgl.push(height[i]);
            }
            else ngl[i] = stgl.top();
        }
        vector<int> ngr(n);
        stack<int> stgr;
        for(int i = n-1;i >= 0;i--){
            while(!stgr.empty() && stgr.top() <= height[i]) stgr.pop();
            if(stgr.empty()){
                ngr[i] = 0;
                stgr.push(height[i]);
            }
            else ngr[i] = stgr.top();
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans += max((min(ngr[i],ngl[i]) - height[i]),0);
        }
        return ans;
    }
};