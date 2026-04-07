/* You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer 
   appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and 
   missing numbers a and b. Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] 
   equals to b.*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        vector<int> freq(N + 1, 0);

        for (auto &row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        int repeating = -1, missing = -1;

        for (int i = 1; i <= N; i++) {
            if (freq[i] == 2) repeating = i;
            else if (freq[i] == 0) missing = i;
        }

        return {repeating, missing};
    }
};