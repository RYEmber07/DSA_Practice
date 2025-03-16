// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;
        while (high >= low){
            mid = low + (high - low) / 2;
            int reqTime = 0;
            for (int j = 0;j < piles.size();j++){
                reqTime += ceil((double)piles[j] / (double)mid);
                if (reqTime > h){
                    low = mid + 1;
                    break;
                }
            }
            if (reqTime <= h){
                high = mid - 1;
            }
        }
        return low;
    }
};

// TC O(n*log(max_element)) SC O(1)
