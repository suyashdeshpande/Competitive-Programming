class Solution {
public:
    void solve(vector<string>&arr, int i, string s, int &ans) {
        // cout << s << endl;
        vector<int>f(26);
        for(char i :s) {
            f[i - 'a']++;
            if(f[i - 'a'] > 1) return;
        }
        ans = max(ans, (int)s.length());
        if(i == arr.size()) return;
        solve(arr, i + 1, s, ans);
        solve(arr, i + 1, s + arr[i], ans);
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        int ans = 0;
        solve(arr, 0, s, ans);
        return ans;
    }
};
