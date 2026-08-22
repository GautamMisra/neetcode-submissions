class Solution {
public:
bool isafe(int row,int col,vector<string>&board,int n){
    for(int r=row-1;r>=0;r--){        //same col
        if (board[r][col]=='Q')
        return false;
    }
    int r = row - 1;                    //diagonal left
    int c = col - 1;

    while(r >= 0 && c >= 0) {
        if(board[r][c] == 'Q')
            return false;

        r--;
        c--;
    }

    int ro = row - 1;                    //diagonal right
    int co = col + 1;

    while(ro >= 0 && co < n) {
        if(board[ro][co] == 'Q')
            return false;

        ro--;
        co++;
    }
    return true;
}
    void soln(int row,int n,vector<string>&board,vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isafe(row,col,board,n)){
                board[row][col]='Q';
                soln(row+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }  
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>>ans;
        int row,col;
        soln(0,n,board,ans);
        return ans;
    }
};
