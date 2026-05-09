#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int targetTickets = tickets[k];
        
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                time += min(tickets[i], targetTickets);
            } else {
                time += min(tickets[i], targetTickets - 1);
            }
        }
        
        return time;
    }
};