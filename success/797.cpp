class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        DepthSearch(0, graph);       
        return paths;        
    }

private:
    vector<vector<int>> paths;
    vector<int> path;
    
    void DepthSearch(int v, const vector<vector<int>>& graph) {
        
        path.push_back(v);
        
        if (v == graph.size() - 1) {
            paths.push_back(path);
            path.pop_back();
            return;
        }      
        
        for (const int u : graph[v]) {
            DepthSearch(u, graph);
        }
        
        path.pop_back();
        
    }
};