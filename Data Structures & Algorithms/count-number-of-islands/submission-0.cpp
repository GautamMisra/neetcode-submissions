class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid){
        int row=grid.size(),col=grid[0].size();
        if(r<0||r>=row||c<0||c>=col||grid[r][c]=='0')
            return;
        grid[r][c]='0';
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            bfs(r+dr[k],c+dc[k],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r,c,count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
