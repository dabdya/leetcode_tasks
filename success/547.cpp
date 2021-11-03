class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        map<int, set<int>> graph;
        
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                
                if (isConnected[i][j] == 1) {
                    graph[i].insert(j);
                    graph[j].insert(i);
                }         
            }
        }
        
        set<int> visited;
        int provinces = 0;
        
        for (const auto& item : graph) {
            if (visited.count(item.first) == 0) {
                DepthSearch(item.first, graph, visited);
                provinces++;
            }
        }
        
        return provinces;
    }
    
private:
    void DepthSearch(int v, map<int, set<int>>& graph, set<int>& visited) {
        
        int n = graph.size();
        int m = graph[0].size();
        
        visited.insert(v);
        for (const int& u : graph[v]) {
            if (visited.count(u) == 0) {
                DepthSearch(u, graph, visited);
            }
        }
        
    }
};