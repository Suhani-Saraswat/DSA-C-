#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, res);
            path.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, nums, path, res);
        return res;
    }
};