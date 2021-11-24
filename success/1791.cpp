class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int, int> g;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u]++;
            g[v]++;
        }
        
        pair<int, int> result = { 0, 0 };
        for (const auto& [key, value] : g) {
            if (value > result.second) {
                result = { key, value };
            }
        }
        
        return result.first;
    }
};