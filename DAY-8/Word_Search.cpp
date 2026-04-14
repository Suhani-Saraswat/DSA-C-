#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {
        if (k == word.length()) return true;

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[k]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '\0';

        bool found = dfs(board, word, r + 1, c, k + 1) ||
                    dfs(board, word, r - 1, c, k + 1) ||
                    dfs(board, word, r, c + 1, k + 1) ||
                    dfs(board, word, r, c - 1, k + 1);

        board[r][c] = temp;

        return found;
    }
};