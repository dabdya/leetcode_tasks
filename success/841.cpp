class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        map<int, set<int>> graph;
        for (int i = 0; i < rooms.size(); i++) {
            for (const auto& u : rooms[i]) {
                graph[i].insert(u);
            }
        }

        if (graph.count(0) == 0) return false;
        search(0, graph);

        return visited.size() == rooms.size();
    }

private:
    set<int> visited;

    void search(int v, const map<int, set<int>>& graph) {
        visited.insert(v);

        if (graph.count(v) == 0) return;

        for (const auto& u : graph.at(v)) {
            if (visited.count(u) == 0) {
                search(u, graph);
            }
        }
    }
};