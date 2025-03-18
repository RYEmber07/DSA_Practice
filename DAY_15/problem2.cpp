// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m - 1, mid, ans = -1;
        while (high >= low){
            mid = low + (high - low) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                ans = mid;
                break;
            }
            else if (target > matrix[mid][n - 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if (ans == -1){ return false; }
        return binary_search(matrix[ans].begin(), matrix[ans].end(), target);
    }
};

// Find the row for which the target might be there using binary search , then do a binary search on that potential row 
// TC O(log(m)+log(n)) == O(log(m*n)) SC O(1)

// or 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1, mid;
        while (high >= low){
            mid = low + (high - low) / 2;
            int row = mid / n, col = mid % n;
            if (matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};

// TC O(log(m*n)) SC O(1)
// Approach : We assume in mind that the 2D array has been flattened and find the row and col for each time we find mid