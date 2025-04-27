// 51. N-Queens
// https://leetcode.com/problems/n-queens/

class Solution {
public:
    void generate(vector<vector<string>>& ans, vector<string>& board, int n, int row, vector<bool>& usedCols,
        vector<bool>& leftDiags, vector<bool>& rightDiags){
        if (row == n){
            ans.emplace_back(board);
            return;
        }
        for (int col = 0;col < n;col++){
            if (!(usedCols[col] || leftDiags[row - col + n - 1] || rightDiags[row + col])){
                usedCols[col] = true;
                leftDiags[row - col + n - 1] = true;
                rightDiags[row + col] = true;

                board[row][col] = 'Q';
                generate(ans, board, n, row + 1, usedCols, leftDiags, rightDiags);
                board[row][col] = '.';

                usedCols[col] = false;
                leftDiags[row - col + n - 1] = false;
                rightDiags[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> usedCols(n, false);
        vector<bool> leftDiags(2 * n - 1, false);
        vector<bool> rightDiags(2 * n - 1, false);

        generate(ans, board, n, 0, usedCols, leftDiags, rightDiags);
        return ans;
    }
};

// TC O(n!){you can think of it like for the first queen you had n options for column then n-1(at a upperbound) and so on} SC O(k*n^2){for board to return the ans , k is the no. of solutions} + O(n^2){current board} + O(n){the hash vectors} + O(n) {recursive stack space depth} 

// Approach : start by making a n*n board , You need to put every queen in a new row so lets start by placing the queen in the row and now vary the col the queen can be explore for each of such calls in this apporach used a hash to store if queen can be put at the place . 
// this can be checked using usedCols data to check if there was any queen at the column for the rows above , left Diags have a property that row - col (need to store n-2 - (n-2) +1 values ) is always constant , whereas right Diags have a property that row + col is always constant .
// if we ever complete all the rows it means th board was solved for the n queens
