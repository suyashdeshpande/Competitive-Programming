class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int ans = arr[0];
        int suff_no_del = arr[0];
        int suff_del = 0;
        for(int i = 1; i < n; i++) {
            suff_del = max(suff_del + arr[i], suff_no_del);
            suff_no_del = max(suff_no_del + arr[i], arr[i]);
            ans = max({ans, suff_del, suff_no_del});
        }
        return ans;
    }
};
