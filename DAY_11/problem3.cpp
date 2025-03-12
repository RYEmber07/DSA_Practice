// LC 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom){
            for (int i = left;i <= right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top;i <= bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom){
                for (int i = right;i >= left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (right >= left){
                for (int i = bottom;i >= top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

// TC O(row * col)
// SC O(row * col) {though extra space used was constant the space used is just to return the ans}
// Approach : used directions(left,right,top,bottom) , Traverse the matrix in a spiral pattern and keep reducing the boundaries until all elements are collected . Also keep in mind the edge case where top might increase more than bottom and right may become less than left