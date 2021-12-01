class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        if (prerequisites.size() == 0) {
            vector<int> res(numCourses);
            iota(begin(res), end(res), 0);
            return res;
        }
        
        map<int, vector<int>> graph;
        map<int, int> incomes;
        
        for (const auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
            incomes[u]++;
        }
        
        for (const auto& [v, _] : graph) {
            if (colors.count(v) == 0 && has_cyrcle(v, graph)) {
                return { };
            }
        }
        
        colors.clear();
        
        for (const auto& [v, _] : graph) {
            if (colors.count(v) == 0) {
                traverse(v, graph, incomes);
            }         
        }
        
        set<int> s(begin(path), end(path));
        for (int i = 0; i < numCourses; i++) {
            if (s.count(i) == 0) {
                path.push_back(i);
            }
        }
             
        return path;
    }
    
private:
    map<int, char> colors;
    vector<int> path;
    
    void traverse(int v, map<int, vector<int>>& graph, map<int, int>& incomes) {
        
        if (--incomes[v] >= 0) {
            return;
        }
        colors[v] = '1';
        path.push_back(v);
        
        for (const auto& u : graph[v]) {
            if (colors.count(u) == 0) {
                traverse(u, graph, incomes);
            }
        }
    }
    
    bool has_cyrcle(int v, const map<int, vector<int>>& graph) {
        
        colors[v] = 'g';
        
        for (const auto& u : graph.at(v)) {
            
            if (colors.count(u) == 1 && colors[u] == 'g') {
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