#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;

            if (i > index && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, target, candidates, path, res);
        return res;
    }
};