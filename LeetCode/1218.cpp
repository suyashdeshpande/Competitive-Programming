class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int ans = 1;
        int n = arr.size();
        unordered_map<int, int>m;
        for(int i = 0; i < n; i++) {
            if(m[arr[i] - diff])
                m[arr[i]] = m[arr[i] - diff] + 1;
            else m[arr[i]] = 1;
            ans = max(ans, m[arr[i]]);
        }
        return ans;
    }
};
