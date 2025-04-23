// 79. Word Search
// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool generate(vector<vector<char>>& board, const string& word, int indx, int i, int j, int n, int m){
        if (indx == word.length()){
            return true;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[indx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool flag =
            generate(board, word, indx + 1, i - 1, j, n, m) ||
            generate(board, word, indx + 1, i + 1, j, n, m) ||
            generate(board, word, indx + 1, i, j - 1, n, m) ||
            generate(board, word, indx + 1, i, j + 1, n, m);
        board[i][j] = temp;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (generate(board, word, 0, i, j, n, m)){
                    return true;
                }
            }
        }
        return false;
    }
};

// TC = O(n × m × 3^L) SC O(L) (due to recursion stack)
// Approach : the first element to be chosen will always be any from the m*n possible squares on the box , explore around 3 directions , atleast 1 direction is always blocked , if the chosen block is different then what should be there according to the word return , mark the already visited blocks (blocks that match the word till now) as done so we dont repeat them , move in possible directions , remeber to use || condns as it says a lot of runtime as || work on switches no further check will be made if 1 codn is checked and is true , if we explore till the last word character it means we have found the path return true .