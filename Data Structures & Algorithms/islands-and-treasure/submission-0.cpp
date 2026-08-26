class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr<row&&nc<col && nr>=0 && nc>=0 &&grid[nr][nc] == 2147483647) {
                    q.push({nr,nc});
                    grid[nr][nc] = grid[r][c] + 1;
                }
                else
                    continue;
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0){
                    q.push({i,j});
                    
                }
                else 
                    continue;
            }
        }
        bfs(q,grid);
    }
};
