class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxarea = 0,i = 0,j = height.size() - 1;
        while(i < j){
            mxarea = max(mxarea,(j - i) * min(height[i],height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return mxarea;
    }
};