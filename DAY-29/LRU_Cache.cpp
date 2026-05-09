#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    int cap;
    std::list<pair<int, int>> l;
    std::unordered_map<int, std::list<pair<int, int>>::iterator> m;

public: 
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->second = value;
            l.splice(l.begin(), l, m[key]);
            return;
        }
        
        if (l.size() == cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
        
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */