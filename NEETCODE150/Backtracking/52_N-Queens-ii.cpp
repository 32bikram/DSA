class Solution {
public:
    int ans = 0;

    //idx is row no
    //strs is the solution for cureent row 0, Queen position
    //str is current row solution
    //diag1 is right diagonal from down, and diag2 is left diagonal from down


    // void back(vector<int> &diag1, vector<int> &diag2, vector<int> &col, int idx, int n, 
    //                                                                 vector<string> &strs){
    void back(vector<int> &diag1, vector<int> &diag2, vector<int> &col, int idx, int n){
        if(idx == n){
            ans++;
            return;
        }
        // string str = "";
        for(int i = 0; i<n; i++){

            int diag1_idx = idx - i + (n-1);
            int diag2_idx = idx + i;

            if(col[i]==0 && diag1[diag1_idx]== 0 && diag2[diag2_idx]==0){
            // int t = 0;
            // while(t<i){
            //     str+= '.';
            //     t++;
            // }
            // str += 'Q';
            col[i] = 1;
            diag1[diag1_idx] = 1;
            diag2[diag2_idx] = 1;
            // t = i+1;
            // while(t<n){
            //     str += '.';
            //     t++;
            // }
            // strs.push_back(str);
            // back(diag1, diag2, col, idx+1, n, strs);
            back(diag1, diag2, col, idx+1, n);
            // strs.pop_back();
            col[i] = 0;
            diag1[diag1_idx] = 0;
            diag2[diag2_idx] = 0;
            }

            // str = "";
        }
    }

    int totalNQueens(int n){
        vector<int> col(n,0);
        vector<int> diag1((2*n)-1, 0);
        vector<int> diag2((2*n)-1, 0);
        // vector<string> strs;
        // back(diag1, diag2, col, 0, n, strs);
        back(diag1, diag2, col, 0, n);
        return ans;
    }
};
