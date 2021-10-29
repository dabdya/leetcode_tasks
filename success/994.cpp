#include <queue>
#include <tuple>


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int>> rotten_oranges;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    rotten_oranges.push({ i, j });
                }
            }
        }

        int result = BreadthSearch(grid, rotten_oranges);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return result;
    }

private:
    int BreadthSearch(vector<vector<int>>& grid, queue<tuple<int, int>>& rotten_oranges) {

        int minutes = 0;
        int n = grid.size();
        int m = grid[0].size();

        while (rotten_oranges.size() != 0) {

            int rotten_count = rotten_oranges.size();
            for (int k = 0; k < rotten_count; k++) {

                tuple<int, int> rotten_orange = rotten_oranges.front();
                rotten_oranges.pop();

                int i = get<0>(rotten_orange);
                int j = get<1>(rotten_orange);

                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    rotten_oranges.push({ i - 1, j });
                }

                if (i + 1 < n && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    rotten_oranges.push({ i + 1, j });
                }

                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    rotten_oranges.push({ i, j - 1 });
                }

                if (j + 1 < m && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    rotten_oranges.push({ i, j + 1 });
                }
            }

            if (rotten_oranges.size() != 0) {
                minutes++;
            }
        }
        return minutes;
    }
};