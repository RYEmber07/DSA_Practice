// 2591. Distribute Money to Maximum Children
// https://leetcode.com/problems/distribute-money-to-maximum-children/description/?envType=problem-list-v2&envId=math

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children){
            return -1;
        }
        money -= children;
        int count = 0;
        while (money >= 7 && children > 0) {
            money -= 7;
            count++;
            children--;
        }
        if (children == 1 && money == 3) {
            count--;
        }
        if (money > 0 && children == 0) {
            return count - 1;
        }
        return count;
    }
};