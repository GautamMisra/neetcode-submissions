class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                string row=string(1,board[i][j])+"row"+to_string(i);
                string col=string(1,board[i][j])+"col"+to_string(j);
                string box=string(1,board[i][j])+"box"+to_string((i/3)*3+(j/3));

                if(seen.count(row)||seen.count(col)||seen.count(box))
                    return false;
                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
        return true;
    }
};
