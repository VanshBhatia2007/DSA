class Solution {
public:
    bool issafe(vector<string> &board, int row, int col, int n){
    // Horizontal - check left only (right is empty, queens placed col by col)
    for(int j = 0; j < col; j++){
        if(board[row][j] == 'Q') return false;
    }

    // Vertical - check above only (below is empty)
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q') return false;
    }

    // Upper-left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q') return false;
    }

    // Upper-right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

    void nqueens(vector<string> &board, int row,int n,vector<vector<string>> &ans){
        //base case
        if(row==n){
            ans.push_back({board});
            return;
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j] = 'Q';
                nqueens(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;
        
        nqueens(board,0,n,ans);
        return ans;
    }
};