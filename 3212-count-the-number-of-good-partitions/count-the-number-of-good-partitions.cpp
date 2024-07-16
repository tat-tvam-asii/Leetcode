class Solution {
public:
    int numberOfGoodPartitions(vector<int>& A) {
        int res = 1, n = A.size(), mod = 1e9 + 7;
        unordered_map<int, int> last;
        for (int i = 0; i < n; ++i) {
            last[A[i]] = i;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            res = i > j ? (res * 2) % mod : res;
            j = max(j, last[A[i]]);
        }
        return res;
    }
};