class Solution {
public:
    
    int robber(int l, int r, vector<int>&nums) {
        int include = 0, exclude = 0;
        int ans = 0;
        for(int i = l; i <= r; i++) {
            int temp1 = include, temp2 = exclude;
            include = temp2 + nums[i];
            exclude = max(temp1, temp2);
            ans = max(include, exclude);
        }
        return ans;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        return max(robber(0, n-2, nums), robber(1, n-1, nums));
    
    }
};
