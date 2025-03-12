// LC 48. Rotate Image
// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0;i < matrix.size();i++){
            for (int j = 0;j < matrix[0].size();j++){
                if (j > i){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for (int i = 0;i < matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// TC O(n square) SC O(1)
// First transpose the matrix and thne reverse all the rows 