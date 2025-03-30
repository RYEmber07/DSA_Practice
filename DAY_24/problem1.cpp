// 838. Push Dominoes
// https://leetcode.com/problems/push-dominoes/description/?envType=problem-list-v2&envId=string

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        int i = 0, j = 1;
        while (j < dominoes.size()){
            while (dominoes[j] == '.'){
                j++;
            }

            if (dominoes[i] == dominoes[j]){
                for (int k = i + 1;k < j;k++){
                    dominoes[k] = dominoes[i];
                }
            }
            else if (dominoes[i] == 'R' && dominoes[j] == 'L'){
                for (int k = i + 1;k < j;k++){
                    if (k - i < j - k){ dominoes[k] = 'R'; }
                    else if (k - i > j - k){ dominoes[k] = 'L'; }
                }
            }

            i = j;
            j++;
        }
        return dominoes.substr(1, dominoes.size() - 2);
    }
};

// TC O(n) SC O(1)
// Approach : add a L and a R at the start and end respectively so we can make different segements for dealing with variosu types of cases .
// if L L then everything inside will be L similarly for R . if L R elements inside remain unchanged . if R and L now check for each point who is it most closest to if it si in middle then it remains '.' .