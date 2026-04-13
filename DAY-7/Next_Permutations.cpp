#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first element from the right that is smaller than its successor
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // 2. Find the smallest element to the right of i that is larger than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap the pivot with its successor
            swap(nums[i], nums[j]);
        }

        // 3. Reverse the portion of the array to the right of the pivot
        // If i was -1, this reverses the entire array (the lowest possible order)
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};