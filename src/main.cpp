/*
 * Author: Shomurod
 * Date: 8.11.23
 * Name: Shomurod Anvarov
 */
//1
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

//5
#include <bits/stdc++.h>
using namespace std;

struct Move {
    int disk;
    char from_rod, to_rod;
};

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    stack<Move> moves;
    Move move;
    int total_moves = (1 << n) - 1;

    for (int i = n; i >= 1; i--) {
        move.disk = i;
        move.from_rod = from_rod;
        move.to_rod = aux_rod;
        moves.push(move);
    }

    for (int move_count = 1; move_count <= total_moves; move_count++) {
        move = moves.top();
        moves.pop();

        int disk = move.disk;
        char from = move.from_rod;
        char to = move.to_rod;

        cout << "Move disk " << disk << " from rod " << from << " to rod " << to << endl;

        char temp = from;
        from = aux_rod;
        aux_rod = temp;

        move.disk = disk - 1;
        move.from_rod = from;
        move.to_rod = to;
        moves.push(move);
    }
}

int main() {
    int N = 3;

    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
//3
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int evaluatePostfixExpression(const string &expression) {
    vector<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
       
            operands.push_back(c - '0');
        } else if (c == '+' || c == '-' || c == '*') {
          
            int operand2 = operands.back();
            operands.pop_back();
            int operand1 = operands.back();
            operands.pop_back();

            int result;
            if (c == '+') {
                result = operand1 + operand2;
            } else if (c == '-') {
                result = operand1 - operand2;
            } else if (c == '*') {
                result = operand1 * operand2;
            }

            operands.push_back(result);
        }
    }

    return operands.back();
}

int main() {
    string expression;
    cin >> expression;

    int result = evaluatePostfixExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}

//4
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<stack<int>> stacks(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
        }
    }

    for (int type = 1; type <= n; type++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!stacks[i].empty() && stacks[i].top() == type) {
                stacks[i].pop();
                cout << i + 1 << " " << type << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "0" << endl;
            return 0;
        }
    }

    return 0;
}
