/*
 * Author: Shomurod
 * Date: 8.11.23
 * Name: Shomurod Anvarov
 */

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    bool isEmpty() {
        return !top;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl; // prints: 3
    s.pop();
    cout << s.top() << endl; // prints: 2

    return 0;
}
