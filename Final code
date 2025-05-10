#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char ch) {
        Node* newNode = new Node();
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';
        }
        char ch = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return ch;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isPalindrome(const string& str) {
    Stack stack;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != stack.pop()) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
