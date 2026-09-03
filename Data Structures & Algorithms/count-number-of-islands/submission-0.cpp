class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'){
                    count++;
                    solvebfs(grid,i,j);
                }
            }
        }
        return count;
    }

    void solvebfs(vector<vector<char>>& grid, int x, int y)
    {
        int m=grid.size();
        int n = grid[0].size();
        vector<int> dx={0,1,0,-1};
        vector<int> dy={-1,0,1,0};

        stack<pair<int,int>> s;
        s.push({x,y});
        
        while(!s.empty())
        {
            auto it = s.top();
            int a= it.first;
            int b= it.second;
            grid[a][b]='0';

            s.pop();
            for(int i=0;i<4;i++)
            {
                int nx= a+dx[i];
                int ny = b+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1')
                {
                    s.push({nx,ny});
                }
            }
        }
    }
};
