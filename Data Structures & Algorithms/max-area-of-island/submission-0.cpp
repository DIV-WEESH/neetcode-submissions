class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        
        int maxarea=0;
        int area=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                   area=solvebfs(grid,i,j);
                }
                maxarea= max(maxarea,area);
            }
        }
        return maxarea;
    }


    int solvebfs(vector<vector<int>>& grid, int x, int y)
    {
        int m= grid.size();
        int n = grid[0].size();
        vector<int> dx={0,1,0,-1};
        vector<int> dy={-1,0,1,0};
        int area= 1;

        //stack<pair<int,int>> s;
        queue<pair<int,int>> q;
        q.push({x,y});
         grid[x][y]='0';
        
        while(!q.empty())
        {
            auto it = q.front();
            int a= it.first;
            int b= it.second;
            grid[a][b]=0;
            
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx= a+dx[i];
                int ny = b+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1)
                {
                    q.push({nx,ny});
                     grid[nx][ny]=0;
                     area++;
                }
            }
        }
        return area;
    }
};
