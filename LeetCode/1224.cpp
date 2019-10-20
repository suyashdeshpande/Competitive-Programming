class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        map<int, int> freq_freq;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(freq[x] > 0) {
                if(--freq_freq[freq[x]] == 0) {
                    freq_freq.erase(freq[x]);
                }
            }
            ++freq[x];
            ++freq_freq[freq[x]];
            
            bool flag = false;
            
            if((int)freq_freq.size() <= 2) {
                pair<int, int>p = *freq_freq.begin();
                if((int)freq_freq.size() == 1) {
                    if(p.first == 1) {
                        flag = true;                        
                    }
                    if(p.second == 1) {
                        flag = true;
                    }
                }
                else {
                    pair<int, int>q = *freq_freq.rbegin();
                    if(p.first == 1 && p.second == 1) {
                        flag = true;
                    }
                    if(p.first + 1 == q.first && q.second == 1) {
                        flag = true;
                    }
                }
            }
            
            
            if(flag) {
                ans = i + 1;
            }
        }
        return ans;
    }
};
