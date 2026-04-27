class Solution {
    int m, n;
    static constexpr int dirs[7][4] = {
        {},
        {1, 1, 0, 0},
        {0, 0, 1, 1}, 
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 0}
    };
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    static inline int opposite(int edge) {
        switch(edge) {
            case 0:
                return 1;
            case 1:
                return 0;
            case 2:
                return 3;
            case 3:
                return 2;
            break;
        }
        return -1;
    }
    static inline bool connected(int a, int b, int dir) {
        return dirs[a][dir] && dirs[b][opposite(dir)];
    }
    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == m - 1 && y == n - 1) return true;
        int type = grid[x][y];
        grid[x][y] = 0;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] == 0) continue;
            if (connected(type, grid[nx][ny], dir) && dfs(grid, nx, ny)) return true;
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return dfs(grid, 0, 0);
    }
};