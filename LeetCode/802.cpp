class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, int node, vector<int>&color) {
        if(color[node] != 0) return color[node] == 1;
        color[node] = 2;
        for(int i: graph[node]) {
            if(!dfs(graph, i, color)) return false;
        }
        color[node] = 1;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        if(!graph.size()) return ans;
        int n = graph.size();
        vector<int>color(n);
        for(int i = 0; i < n; i++)
            if(dfs(graph, i, color))
                ans.emplace_back(i);
        return ans;
    }
};
