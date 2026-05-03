#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;
                
                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                
                curr->next = childHead;
                childHead->prev = curr;
                
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        
        return head;
    }
};