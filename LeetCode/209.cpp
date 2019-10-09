class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            while(sum >= s) {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};
