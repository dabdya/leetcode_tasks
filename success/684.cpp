class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Нужно удалить одно ребро так, чтобы связность не нарушилась и не было циклов

        /*
            Неориентированность в этой задаче испортить никак нельзя.

            Если граф был связен, а по условию до добавления ребра это именно так,
            и в него добавили ребро -> связность не нарушилась
            Значит за связность беспокоиться не нужно.

            Если в графе не было циклов, и после добавления ребра их нет, то удалять ничего не нужно
            А значит и задача не имеет смысла, потому что нужно вернуть хоть какое-то ребро

            Если при добавлении циклы появились -> нужно от них избавиться.
            Если циклы были изначально и добавленное ребро образовало еще один цикл,
            то решения с удалением лишь одного ребра нет, поскольку для удаления двух циклов,
            нужно удалить хотя бы по одному ребру из каждого

            Значит все сводится к тому, что нужно найти единственный цикл и выбрать в нем
            самое последнее ребро относительно входных данных
        */

        map<int, vector<int>> graph;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        DepthSearch(1, 1, graph);

        set<vector<int>> edges_in_cyrcle;
        for (int i = 0; i < path.size() - 1; i++) {
            vector<int> edge = { path[i], path[i + 1] };
            sort(edge.begin(), edge.end());
            edges_in_cyrcle.insert(edge);
        }

        vector<int> edge = { path[path.size() - 1], path[0] };
        sort(edge.begin(), edge.end());
        edges_in_cyrcle.insert(edge);

        for (int i = edges.size() - 1; i >= 0; i--) {
            if (edges_in_cyrcle.count(edges[i])) {
                return edges[i];
            }
        }

        return { };
    }

private:
    vector<int> path;
    set<int> visited;

    bool DepthSearch(int v, int from, const map<int, vector<int>>& graph) {

        if (visited.count(v) == 1) {
            vector<int> backtrack;
            for (int i = path.size() - 1; i >= 0; i--) {
                backtrack.push_back(path[i]);
                if (path[i] == v) break;
            }
            path = backtrack;
            return true;
        }

        path.push_back(v);
        visited.insert(v);

        for (const auto& u : graph.at(v)) {
            if (u != from && DepthSearch(u, v, graph)) 
                return true;
        }

        path.pop_back();
        visited.erase(v);
        return false;
    }
};