// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=greedy

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0){ return true; }
        int validPlaces = 0;
        for (int i = 0;i < flowerbed.size();i++){
            if (((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) && (flowerbed[i] == 0)){
                validPlaces++;
                flowerbed[i] = 1;
            }
        }
        if (validPlaces >= n){
            return true;
        }
        return false;
    }
};