#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        unordered_set<int> cols;
        unordered_set<int> posDiag; 
        unordered_set<int> negDiag; 
        
        backtrack(0, n, board, res, cols, posDiag, negDiag);
        return res;
    }

private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res,
        unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, board, res, cols, posDiag, negDiag);

            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};