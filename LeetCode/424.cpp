class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>count(26);
        int i = 0, maxCount = 0, maxLength = 0;
        for(int j = 0; j < n; j++) {
            maxCount = max(maxCount, ++count[s[j] - 'A']);
            while(j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};
