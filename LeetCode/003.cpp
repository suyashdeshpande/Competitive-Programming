class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> se;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (se.find(s[j]) == se.end()){
                se.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {
                se.erase(s[i++]);
            }
        }
        return ans;
    }
    
};
