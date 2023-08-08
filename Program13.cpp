/*
Description
Problem Statement:
Data are pushed to (PUSH operation) and popped from (POP operation) a stack in the following order:
PUSH 3; TOP; PUSH 7; TOP; PUSH 6; PUSH 9; TOP; POP; POP; TOP; where the PUSH, POP, Top are the stack operations. 
Write the values returned by TOP for the sequence of operations above. Also check stack is full or empty.

Sample output from above scenario:
Output:
3 7 9 7
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    //Stack() : top(-1) {}

    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (!isFull()) {
            top++;
            arr[top] = value;
        } else {
            cout << "Stack is full! Cannot push " << value << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "Stack is empty! Cannot pop." << endl;
        }
    }

    int topValue() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "Stack is empty! Cannot get top value." << endl;
            return -1; // Return a default value 
            
            }
    }
};

int main() {
    Stack stack;

    stack.push(3);
    cout << stack.topValue() << " ";

    stack.push(7);
    cout << stack.topValue() << " ";

    stack.push(6);
    stack.push(9);
    cout << stack.topValue() << " ";

    stack.pop();
    stack.pop();
    cout << stack.topValue() << " ";

    return 0;
}
