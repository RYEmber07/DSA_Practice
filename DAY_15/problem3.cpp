// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0){
            if (matrix[row][col] == target){
                return true;
            }
            else if (target > matrix[row][col]){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};

// Approach : This approach starts from the top-right corner of the matrix and moves left if the current element is greater than the target or moves down if it's smaller.
// TC O(m+n) SC O(1)
