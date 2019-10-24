class Solution {
public:
    // int longestValidParentheses(string s) {
    //     int n = s.length();
    //     int ans = 0;
    //     vector<int>dp(n, 0);
    //     for(int i = 1; i < s.length(); i++) {
    //         if(s[i] == ')') {
    //             if(s[i - 1] == '(') {
    //                 dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
    //             }
    //             else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
    //                 dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] + 2 : 2);
    //             }
    //             ans = max(ans, dp[i]);
    //         }
    //     }
    //     return ans;
    // }
    
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};
