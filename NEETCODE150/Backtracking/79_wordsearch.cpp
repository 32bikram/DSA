class Solution {
public:
    bool ans = false;
    void back(vector<vector<char>>& board, string word, int x, int y,
                                                        int curr_ind){
        if(curr_ind == word.size()-1 && word[curr_ind] == board[x][y]){
            ans = true;
            return;
        }

        if(word[curr_ind] == board[x][y]){
            board[x][y] = '#';
            //marking the character as used like for aba same characters could be used twice
            curr_ind++;
            if(y-1>=0 && board[x][y-1]==word[curr_ind]){
                back(board, word, x, y-1, curr_ind);
            }
            
            if(y+1<board[0].size() && board[x][y+1]==word[curr_ind]){
                back(board, word, x, y+1, curr_ind);
            }
            
            if(x-1>=0 && board[x-1][y]==word[curr_ind]){
                back(board, word, x-1, y, curr_ind);
            }
            
            if(x+1<board.size() && board[x+1][y]==word[curr_ind]){
                back(board, word, x+1, y, curr_ind);
            }
            
            board[x][y] = word[curr_ind-1];
            //restoring the board
            return;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i = 0, j = 0, curr_ind = 0;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    back(board, word, i, j, curr_ind);
                }
            }
        }
        return ans;
    }
};

