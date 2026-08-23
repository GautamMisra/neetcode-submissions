class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& grid){
        int row=grid.size(),col=grid[0].size();
        int count=1;
        if(r<0||r>=row||c<0||c>=col||grid[r][c]==0)
            return 0;
        grid[r][c]=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            count+=dfs(r+dr[k],c+dc[k],grid);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int currentarea=dfs(i,j,grid);
                    ans=max(ans,currentarea);
                }
            }
        }
        return ans;
    }
};
