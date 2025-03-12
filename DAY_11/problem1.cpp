// LC 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0;i < numRows;i++){
            for (int j = 0;j <= i;j++){
                if (j == 0 || j == i){ ans[i].emplace_back(1); }
                else{
                    int value = ans[i - 1][j - 1] + ans[i - 1][j];
                    ans[i].emplace_back(value);
                }
            }
        }
        return ans;
    }
};

// TC O(n square) SC O(n square) {though this space is only to return the answer and no extra space was used}
