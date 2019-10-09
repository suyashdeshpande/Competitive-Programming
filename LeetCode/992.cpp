class Solution {
public:
    
    int solve(vector<int>& A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++) K--;
            while (K < 0) {
                --count[A[i]];
                if (!count[A[i]]) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return solve(A, K) - solve(A, K - 1);
    }
    
};
