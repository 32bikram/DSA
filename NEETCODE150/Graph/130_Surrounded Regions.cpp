class Solution {
public:
//instead of finding out which cells are closed we do, the cells that are safe like ones in the border and expand inside
//just like the pacific atlantic question, we find those that are already connected to the ocean and expand inside
    int rows, cols;
    vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};

    void DFS(int row, int col, vector<vector<char>> &board){
        if(board[row][col]=='S' || board[row][col]=='X') return;
        board[row][col]='S';
        int nrow, ncol;
        for(int i = 0; i<dir.size(); i++){
            nrow = row + dir[i][0], ncol = col + dir[i][1];
            if(nrow<0 || nrow>=rows || ncol<0 || ncol>=cols) continue;
            DFS(nrow, ncol, board);
        } 
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size(), cols = board[0].size();

        for(int i = 0; i<cols; i++){ //first row
            if(board[0][i] == 'O') DFS(0, i, board);
        }

        for(int i = 0; i<rows; i++){ //first col
            if(board[i][0] == 'O') DFS(i,0,board);
        }

        for(int i = 0; i<cols; i++){ //last row
            if(board[rows-1][i] == 'O') DFS(rows-1, i, board);
        }

        for(int i = 0; i<rows; i++){ //last col
            if(board[i][cols-1] == 'O') DFS(i, cols-1, board);
        }
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]=='S') board[i][j] = 'O';
            }
        }
    }
};
