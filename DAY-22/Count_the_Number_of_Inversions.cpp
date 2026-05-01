#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
         int MOD = 1e9 + 7;
        int max_inv = 400;
        vector<int> req(n, -1);
        for (auto& r : requirements) req[r[0]] = r[1];

        vector<long long> dp(max_inv + 1, 0);

        if (req[0] > 0) return 0; 
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            vector<long long> next_dp(max_inv + 1, 0);
            long long current_sum = 0;
            
            for (int j = 0; j <= max_inv; ++j) {
                current_sum = (current_sum + dp[j]) % MOD;
                if (j > i) {
                    current_sum = (current_sum - dp[j - i - 1] + MOD) % MOD;
                }
                next_dp[j] = current_sum;
            }
            
            if (req[i] != -1) {
                int target = req[i];
                for (int j = 0; j <= max_inv; ++j) {
                    if (j != target) next_dp[j] = 0;
                }
            }
            dp = move(next_dp);
        }

        return req[n - 1] == -1 ? 0 : dp[req[n - 1]];
    }
};