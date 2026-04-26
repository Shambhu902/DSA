class Solution {
    const std::vector<std::pair<int, int>> moves = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
public:
    bool check(size_t start, const size_t& n, const size_t& m,
        const vector<vector<char>>& grid,
        vector<vector<bool>>& seen
    ) {
        std::vector<std::tuple<size_t,size_t,size_t>> st;
        st.push_back({start / m, start % m, SIZE_MAX});
        while (!st.empty()) {
            auto [i, j, parent] = st.back();
            st.pop_back();
            if (!seen[i][j]) seen[i][j] = true;
            for (auto [dx, dy] : moves) {
                size_t ni = i + dx;
                size_t nj = j + dy;
                if (ni >= n || nj >= m) continue;
                if (grid[ni][nj] != grid[i][j]) continue;
                if (ni * m + nj == parent) continue;
                if (seen[ni][nj]) return true;
                st.push_back({ni, nj, i * m + j});
            }
        }
        return false;
    };

    bool containsCycle(vector<vector<char>>& grid) {
        size_t n = grid.size(), m = grid[0].size();
        std::vector<std::vector<bool>> seen(n, std::vector<bool>(m, false));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (seen[i][j]) continue;
                if (check(i * m + j, n, m, grid, seen)) return true;
            }
        }
        return false;
    }
};