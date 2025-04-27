// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool solve(vector<vector<char>>& board, bool row[9][9], bool col[9][9], bool box[9][9]){

        for (int i = 0;i < board.size();i++){
            for (int j = 0;j < board[0].size();j++){

                if (board[i][j] == '.'){
                    for (char num = '1';num <= '9';num++){

                        if (!(row[i][num - '0' - 1] || col[j][num - '0' - 1] || box[(i / 3) * 3 + j / 3][num - '0' - 1])){

                            board[i][j] = num;
                            row[i][num - '0' - 1] = col[j][num - '0' - 1] = box[(i / 3) * 3 + j / 3][num - '0' - 1] = true;

                            if (solve(board, row, col, box)){
                                return true;
                            }

                            board[i][j] = '.';
                            row[i][num - '0' - 1] = col[j][num - '0' - 1] = box[(i / 3) * 3 + j / 3][num - '0' - 1] = false;

                        }

                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};
        for (int i = 0;i < 9;i++){
            for (int j = 0;j < 9;j++){
                if (board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    row[i][num - 1] = true;
                    col[j][num - 1] = true;
                    box[(i / 3) * 3 + j / 3][num - 1] = true;
                }
            }
        }
        solve(board, row, col, box);
    }
};

// TC O(9^n) {n is no. of empty cells} SC O(n){recursive stack space} 0<=n<=81 so actually it is constant.

// Also used fixed size 2D arrays to check validity of a box in the board
// Approach : iterate and find the empty pieces on the board put numbers form 1 to 9 there check if it is valid there if valid proceed with checking for further depthif no numebr could be placed there return false if possibility was found return true if the full board was explored for the final depth return true . 