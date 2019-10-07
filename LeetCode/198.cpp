class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int>dp(n, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i] + (i-2 >= 0 ? dp[i-2] : 0));
            ans = max(ans, dp[i]);
        } 
        return ans;
    }
};
