#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty() && freshCount > 0) {
            int currentLevelSize = q.size();
            minutes++;
            
            for (int i = 0; i < currentLevelSize; ++i) {
                pair<int, int> current = q.front();
                q.pop();
                
                for (auto& dir : directions) {
                    int nr = current.first + dir.first;
                    int nc = current.second + dir.second;
                    
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};