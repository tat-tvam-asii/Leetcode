class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& v : image){
            reverse(v.begin(),v.end());
            for(auto& n : v){
                n ^= 1;
            }
        }
        return image;
    }
};