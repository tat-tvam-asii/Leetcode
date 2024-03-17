class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        if(A.size() == 1){
            if(A[0] == 1) return 2;
            else return 1;
        }
        for(int& i : A){
            if(i < 0) i = INT_MIN; 
        }
        for(int i=0;i<A.size();i++){
            if(A[i] != INT_MIN){
                if(abs(A[i]) < A.size()){
                    if(A[abs(A[i])] == INT_MIN) A[abs(A[i])] = -abs(A[i]);
                    else{
                        if(A[abs(A[i])] > 0) A[abs(A[i])] *= -1;
                        else if(A[abs(A[i])] == 0) A[abs(A[i])] = -abs(A[i]);
                    } 
                }
            }
        }
        int i;
        for(i=1;i<A.size();i++){
            if(A[i] >= 0 || A[i] == INT_MIN) return i;
        }
        for(int j=0;j<A.size();j++){
            if(abs(A[j]) == i) return i+1;
        }
        return i;
    }
};