#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            // Using this formula to prevent potential integer overflow
            int mid = left + (right - left) / 2;
            
            // Map the 1D index 'mid' to 2D coordinates [row][col]
            int row = mid / n;
            int col = mid % n;
            int mid_val = matrix[row][col];
            
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};