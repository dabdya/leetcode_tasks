class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> graph;
        
        for (const auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
        }
        
        for (const auto& [v, _] : graph) {
            if (colors.count(v) == 0 && has_cyrcle(v, graph)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    map<int, char> colors;
    
    bool has_cyrcle(int v, const map<int, vector<int>>& graph) {

        colors[v] = 'g';
        
        for (const auto& u : graph.at(v)) {
            
            if (colors.count(u) == 1 && colors[u] == 'g') 
            {
                return true;
            }
            
            if (graph.count(u) == 1 && colors.count(u) == 0 && has_cyrcle(u, graph)) {
                return true;
            } 
        }
        
        colors[v] = 'b';
        return false;     
    }   
};