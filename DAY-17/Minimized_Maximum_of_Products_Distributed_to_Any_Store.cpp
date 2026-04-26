#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canDistribute(int maxQty, int n, vector<int>& quantities) {
        long long storesNeeded = 0;
        for (int q : quantities) {
            storesNeeded += (q + maxQty - 1) / maxQty;
            if (storesNeeded > n) return false;
        }
        return storesNeeded <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 100000;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(mid, n, quantities)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};