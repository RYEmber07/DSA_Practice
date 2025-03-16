// 1283. Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid;
        if (threshold < nums.size()){ return -1; } // for the codn where threshold is smaller than the minm possible sum
        while (high >= low){
            mid = low + (high - low) / 2;
            int sum = 0;
            for (int i = 0;i < nums.size();i++){
                sum += ceil((double)nums[i] / (double)mid);
                if (sum > threshold){
                    low = mid + 1;
                    break;
                }
            }
            if (sum <= threshold){
                high = mid - 1;
            }
        }
        return low;
    }
};

// TC O(n*log(max_element)) SC O(1)