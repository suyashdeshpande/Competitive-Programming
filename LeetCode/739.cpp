class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>s;
        int n = T.size();
        vector<int>ans(n, 0);
        for(int i = 0; i < n; i++) {
            while(!s.empty() && T[s.top()] < T[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
