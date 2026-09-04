class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

       
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto [x,y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < m &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] == INT_MAX) {

                    grid[nx][ny] = grid[x][y] + 1;

                    q.push({nx,ny});
                }
            }
        }
    }
};