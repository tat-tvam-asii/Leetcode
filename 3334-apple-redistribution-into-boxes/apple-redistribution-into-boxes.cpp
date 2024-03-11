class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int sum = accumulate(apple.begin(),apple.end(),0);
        reverse(capacity.begin(),capacity.end());
        int n = capacity.size();
        for(int i=1;i<n;i++) capacity[i] += capacity[i-1];
        return lower_bound(capacity.begin(),capacity.end(),sum) - capacity.begin() + 1;
    }
};