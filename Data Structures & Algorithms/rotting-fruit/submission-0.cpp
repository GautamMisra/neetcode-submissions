class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,int& min,int& fresh,bool & rotten){
        int row = grid.size(), col = grid[0].size();
        while(!q.empty()){
            int size = q.size();
            rotten=false;
            for(int i=0;i<size;i++){
                auto [r, c] = q.front();
                q.pop();
                int dr[]={1,-1,0,0};
                int dc[]={0,0,1,-1};
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr<row&&nc<col&&nr>=0&&nc>=0&&grid[nr][nc]==1){
                        rotten=true;
                        fresh--;
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                    }
                    else
                        continue;
                }
            }
            if(rotten)
                min++;
            else
                continue;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0,min=0;
        bool rotten=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
                else
                    continue;
            }
        }
        bfs(q,grid,min,fresh,rotten);
        if(fresh==0)
            return min;
        else
            return -1;
    }
};
