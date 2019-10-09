class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int n = A.size();
        if(!n) return 0;
        if(n <= k) return n;
        int ans = 0;
        int count = 0;
        int i = 0;
        for(int j = 0; j < n; j++) {
            if(A[j] == 0) count++;
            while(count > k) {
                if(A[i] == 0) count--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
