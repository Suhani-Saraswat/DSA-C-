#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;

        int n = grid.size();
        vector<pair<int, int>> pos(n * n);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                pos[grid[r][c]] = {r, c};
            }
        }

        for (int i = 1; i < n * n; i++) {
            int rowDiff = abs(pos[i].first - pos[i - 1].first);
            int colDiff = abs(pos[i].second - pos[i - 1].second);
            
            if (rowDiff * colDiff != 2) {
                return false;
            }
        }

        return true;
    }
};