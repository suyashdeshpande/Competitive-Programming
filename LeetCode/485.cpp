class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int n = nums.size();
        if(!n) return 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] == 0) {
                i = j + 1;
                continue;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
