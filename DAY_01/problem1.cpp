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

// Alternate Method - Checking Factors

class Solution
{
public:
    bool checki(int i)
    {
        if (i == 1)
        {
            return true;
        }
        if ((i % 2 != 0 && i % 3 != 0 && i % 5 != 0))
        {
            return false;
        }
        return true;
    }
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (checki(i) != 1 || checki(n / i) != 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};