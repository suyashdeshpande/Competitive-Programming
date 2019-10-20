class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        unordered_set<string>s;
        vector<string>ans;
        for(string i: folder) {
            bool parentPresent = false;
            for(int j = 1; j <= i.size(); j++) {
                if(i[j-1] == '/' && s.find(i.substr(0, j-1)) != s.end()) {
                    parentPresent = true;
                }
            }
            if(!parentPresent) {
                s.insert(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
