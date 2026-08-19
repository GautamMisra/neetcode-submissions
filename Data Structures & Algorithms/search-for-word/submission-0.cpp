class Solution {
public:
    bool getword(int row,int col,int idx,vector<vector<char>>& board,string word,vector<vector<bool>>& visited){
    if(row < 0 || row >= board.size() ||
    col < 0 || col >= board[0].size())
        return false;
    if(visited[row][col])
        return false;
    if(board[row][col] != word[idx])
        return false;
    if(idx == word.size()-1)
        return true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    visited[row][col]=true;
    for(int k = 0; k < 4; k++) {
        int nr = row + dr[k];
        int nc = col + dc[k];
        if(getword( nr, nc, idx + 1,board,word,visited))
            return true;
    }
    visited[row][col] = false;
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(
        board.size(),
        vector<bool>(board[0].size(), false)
    );
    int row,col;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(getword(i, j, 0, board, word, visited))
                return true;
        }
    }
    return false;
    }
};
