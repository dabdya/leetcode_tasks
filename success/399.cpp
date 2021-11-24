class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations, vector<double>& values, 
        vector<vector<string>>& queries) {
        
        map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string v = equations[i][0];
            string u = equations[i][1];
            graph[v].push_back({ u, values[i] });
            graph[u].push_back({ v, 1 / values[i] });
        }
        
        vector<double> answers;
        for (const auto& query : queries) {
            string v = query[0];
            string u = query[1];
            if (graph.count(v) == 0 || graph.count(u) == 0) {
                answers.push_back(-1.0);
            }
            else {
                double answer = search(v, u, 1.0, graph);
                visited.clear();
                answers.push_back(answer);
            }  
        }
        
        return answers;
        
    }
    
private:
    set<string> visited;
    
    double search(
        const string& from, const string& to, double curanswer, 
        const map<string, vector<pair<string, double>>>& graph) {
        
        if (from == to) return curanswer;
        visited.insert(from);
        
        double result = -1.0;
        
        for (const auto& [vertice, value] : graph.at(from)) {
            if (visited.count(vertice) == 0) {
                double res = search(vertice, to, curanswer * value, graph);
                result = max(result, res);
            }
        }
        
        return result;
    }
};