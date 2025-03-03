// Good or Bad string
// https://www.geeksforgeeks.org/problems/good-or-bad-string1417/1

class Solution
{
public:
    int isGoodorBad(string s)
    {
        int vowCount = 0, constCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowCount++;
                constCount = 0;
            }
            else if (s[i] == '?')
            {
                vowCount++;
                constCount++;
            }
            else
            {
                vowCount = 0;
                constCount++;
            }

            if (vowCount > 5 || constCount > 3)
            {
                return 0;
            }
        }
        return 1;
    }
};
