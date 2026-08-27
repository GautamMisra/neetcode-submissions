class Solution {
public:
    void dfs(int r, int c,vector<vector<int>>& heights,vector<vector<bool>>& ocean){
        int row=heights.size(),col=heights[0].size();
        if (ocean[r][c])
            return;
        ocean[r][c]=true;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && 
            heights[nr][nc] >=heights[r][c])
                dfs(nr,nc,heights,ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        vector<vector<int>> ans;
        for (int j = 0; j < col; j++) {
            dfs(0, j, heights, pacific);
        }
        for (int i = 0; i < row; i++) {
            dfs(i, 0, heights, pacific);
        }
        for (int j = 0; j < col; j++) {
            dfs(row - 1, j, heights, atlantic);
        }
        for (int i = 0; i < row; i++) {
            dfs(i, col - 1, heights, atlantic);
        }
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
