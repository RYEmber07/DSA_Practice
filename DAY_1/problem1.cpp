// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/?envType=problem-list-v2&envId=math

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            if (n % 3 == 0)
            {
                n /= 3;
            }
            if (n % 5 == 0)
            {
                n /= 5;
            }
        }
        if (n != 1)
        {
            return false;
        }
        return true;
    }
};

// Alternate Method - Using Set

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        vector <int> v;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                v.emplace_back(i);
                v.emplace_back(n/i);
            }
        }
        for (auto it : v)
        {
            if (it == 1)
            {
                continue;
            }
            if ((it % 2 != 0 && it % 3 != 0 && it % 5 != 0))
            {
                return false;
            }
        }
        return true;
    }
};