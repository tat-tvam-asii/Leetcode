class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        A.push_back(0);
        for(int& i : A){
            if(i < 0 || i >= A.size()) i = 0; 
        }
        int n = A.size();
        for(int i=0;i<n;i++){
            A[A[i]%n] += n;
        }
        for(int j=1;j<n;j++){
            if(A[j] < n) return j;
        }
        return n;
    }
};