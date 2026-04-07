/* Given an array nums of size n, return the majority element. The majority element is the element that appears more than 
   ⌊n / 2⌋ times. You may assume that the majority element always exists in the array. */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        //Sort
        sort(nums.begin(), nums.end());

        //Frequency
        int freq = 1, ans = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]){
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }

            if (freq > (n/2)) {
                return ans;
            }
        }

        return ans;
    }
};