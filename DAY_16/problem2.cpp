// Median in a row-wise sorted Matrix
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

int occurences(vector<vector<int>>& mat, int num){
    int count = 0;
    for (int i = 0;i < mat.size();i++){
        count += upper_bound(mat[i].begin(), mat[i].end(), num) - mat[i].begin();
    }
    return count;
}
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int low = 1, high = 2000, mid;
        while (high >= low){
            mid = low + (high - low) / 2;
            if (occurences(mat, mid) > (mat.size() * mat[0].size()) / 2){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

// TC O(log2(max-min)*rows*log(cols)) SC O(1)
// Approach : It is given that the value of any element is between 1 and 2000.
// We will use binary earch on ans and find the no.between 1 and 2000 which has elements less than or equal to it just greater than(m * n) / 2.
// We can do that by doing the upperbound to calculate no.s of elements that are less than or equal to the no.

