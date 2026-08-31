class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c){
        int row=board.size(),col=board[0].size();
        if(r<row && r>=0 && c<col && c>=0){
            board[r][c]='T';
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr<row && nr>=0 && nc<col && nc>=0 && board[nr][nc]=='O'){
                board[nr][nc]='T';
                dfs(board,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
        for(int i=0;i<col;i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            else
                continue;
        }
        for(int i=1;i<row;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            else
                continue;
        }
        for(int i=1;i<col;i++){
            if(board[row-1][i]=='O')
                dfs(board,row-1,i);
            else
                continue;
        }
        for(int i=1;i<row-1;i++){
            if(board[i][col-1]=='O')
                dfs(board,i,col-1);
            else
                continue;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='T')
                    board[i][j]='O';
                else
                    continue;
            }
        }
    }
};
