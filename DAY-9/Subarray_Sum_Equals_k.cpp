#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        prevSum[0] = 1;
        
        int count = 0;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (prevSum.find(currentSum - k) != prevSum.end()) {
                count += prevSum[currentSum - k];
            }
            
            prevSum[currentSum]++;
        }
        
        return count;
    }
};