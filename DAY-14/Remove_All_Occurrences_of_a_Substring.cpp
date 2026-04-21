#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int n = s.length();
        int m = part.length();
        
        for (char c : s) {
            res.push_back(c);
            
            if (res.length() >= m && res.substr(res.length() - m) == part) {
                res.erase(res.length() - m);
            }
        }
        
        return res;
    }
};