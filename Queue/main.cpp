//
//  main.cpp
//  Queue
//
//  Created by Sailender Singh on 17/03/19.
//  Copyright © 2019 Sailender Singh. All rights reserved.
//

#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int key;
        struct Node* next;
        struct Node* end;
        Node() {
            key = 0;
            next = NULL;
            end = NULL;
        };
    };
    
    struct Node* root = NULL;
    int noOfElements = 0;
    
    struct Node* getNode(int key) {
        struct Node* node = new Node();
        node -> key = key;
        return node;
    }
    
public:
    
    bool isEmpty()
    {
        return noOfElements==0;
    }
    
    void push(int key)
    {
        struct Node* node = getNode(key);
        if (root == NULL) {
            root = node;
        } else {
            root -> end -> next = node;
        }
        root -> end = node;
        ++noOfElements;
    }
    
    int pop()
    {
        if (isEmpty()) {
            return -1;
        }
        struct Node* toDelete = root;
        if(noOfElements>1) {
            root = toDelete -> next;
            root -> end = toDelete -> end;
        } else {
            root = NULL;
        }
        int key = toDelete -> key;
        delete toDelete;
        --noOfElements;
        return key;
    }
    
    int peek()
    {
        if (isEmpty()) {
            return -1;
        }
        return root -> key;
    }
    
    void printQueue()
    {
        cout << endl;
        struct Node* localRoot = root;
        while (localRoot != NULL) {
            cout << localRoot -> key << " ";
            localRoot = localRoot -> next;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Queue *queue = new Queue();
    queue -> push(10);
    queue -> push(11);
    queue -> push(12);
    queue -> push(13);
    queue -> push(14);
    queue -> push(15);
    
    queue -> printQueue();
    
    queue -> pop();
    queue -> printQueue();
    
    queue -> pop();
    queue -> printQueue();
    
    queue -> push(16);
    queue -> printQueue();
    
    queue -> pop();
    queue -> pop();
    queue -> pop();
    queue -> pop();
    queue -> pop();
    queue -> pop();
    queue -> pop();
    queue -> printQueue();
    
    cout << "isEmpty() : "<<queue -> isEmpty() << endl;

    return 0;
}
