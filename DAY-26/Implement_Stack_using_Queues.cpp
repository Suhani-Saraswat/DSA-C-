#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();
    
    int x = 10; 

    obj->push(x);
    obj->push(20);
    
    int param_2 = obj->pop(); 
    int param_3 = obj->top(); 
    bool param_4 = obj->empty();

    delete obj;

    return 0;
}