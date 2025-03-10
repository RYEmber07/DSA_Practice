// Maximum Score from Subarray Minimums
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int maxScore = 0;
        for (int i = 0;i < arr.size() - 1;i++){
            maxScore = max(arr[i] + arr[i + 1], maxScore);
        }
        return maxScore;
    }
};
