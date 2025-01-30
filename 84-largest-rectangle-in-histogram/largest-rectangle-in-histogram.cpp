class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n);
        stack<int> stl;
        for(int i = 0;i < n;i++){
            while(!stl.empty() && heights[stl.top()] >= heights[i]) stl.pop();
            if(stl.empty()) nsl[i] = -1;
            else nsl[i] = stl.top();
            stl.push(i);
        }
        vector<int> nsr(n,0);
        stack<int> str;
        for(int i = n-1;i >= 0;i--){
            while(!str.empty() && heights[str.top()] >= heights[i]) str.pop();
            if(str.empty()) nsr[i] = n;
            else nsr[i] = str.top();
            str.push(i);
        }
        int mxArea = 0;
        for(int i = 0;i < n;i++){
            mxArea = max(mxArea,heights[i] * (nsr[i] - nsl[i] - 1));
        }
        return mxArea;
    }
};