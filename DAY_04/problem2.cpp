// Chocolate Distribution Problem
// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int minDiff = INT_MAX;
        for (int i = 0;i <= a.size() - m;i++){
            minDiff = min(minDiff, a[i + m - 1] - a[i]);
        }
        return minDiff;
    }
};