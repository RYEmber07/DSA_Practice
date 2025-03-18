// 1901. Find a Peak Element II
// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
public:
    int findColMax(vector<vector<int>>& mat, int col){
        int maxIndx = 0, maxi = INT_MIN;
        for (int i = 0;i < mat.size();i++){
            if (mat[i][col] > maxi){
                maxi = mat[i][col];
                maxIndx = i;
            }
        }
        return maxIndx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1, mid;
        while (high >= low){
            mid = low + (high - low) / 2;
            int maxIndx = findColMax(mat, mid);
            if ((mid == 0 || mat[maxIndx][mid] > mat[maxIndx][mid - 1]) && (mid == mat[0].size() - 1 || mat[maxIndx][mid] > mat[maxIndx][mid + 1])){
                return { maxIndx,mid };
            }
            else if (mid > 0 && mat[maxIndx][mid] < mat[maxIndx][mid - 1]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return { -1,-1 };
    }
};

// TC O(rows*log(cols)) SC O(1)
// Approach : We use binary search on the columns of the matrix. For each middle column, we find the largest number in that column. 
// If this number is bigger than the numbers to its left and right, we return it as the peak.
// Otherwise , we move to the side with the bigger number and continue searching until we find a peak.