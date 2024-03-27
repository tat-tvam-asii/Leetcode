class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0,j = 0,mx = INT_MIN;
        while(j < A.size()){
            if(A[j] == 0) K--;
            while(K < 0){
                if(A[i++] == 0) K++;
            }
            mx = max(mx,j - i + 1);
            j++;
        }
        return mx;
    }
};