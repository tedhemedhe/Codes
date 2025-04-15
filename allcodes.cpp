// 1. Singly Linked List
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* nextNode;

    node(int value) {
        data = value;
        nextNode = NULL;
    }
};

class SinglyLinkedList {
private:
    node* startNode;

public:
    SinglyLinkedList() {
        startNode = NULL;
    }

    void insertValue(int value) {
        node* newNode = new node(value);
        if (startNode == NULL) {
            startNode = newNode;
        } else {
            node* currentNode = startNode;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
        }
    }

    void deleteValue(int value) {
        if (startNode == NULL) {
            return;
        }

        if (startNode->data == value) {
            node* temp = startNode;
            startNode = startNode->nextNode;
            delete temp;
            return;
        }

        node* currentNode = startNode;
        while (currentNode->nextNode != NULL && currentNode->nextNode->data != value) {
            currentNode = currentNode->nextNode;
        }

        if (currentNode->nextNode != NULL) {
            node* temp = currentNode->nextNode;
            currentNode->nextNode = temp->nextNode;
            delete temp;
        }
    }

    bool searchValue(int value) {
        node* currentNode = startNode;
        while (currentNode != NULL) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->nextNode;
        }
        return false;
    }

    void displayList() {
        node* currentNode = startNode;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList myList;
    myList.insertValue(10);
    myList.insertValue(20);
    myList.insertValue(30);

    cout << "Initial List: ";
    myList.displayList();

    myList.deleteValue(20);
    cout << "After Deleting 20: ";
    myList.displayList();

    cout << "Searching for 10: ";
    if (myList.searchValue(10)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for 50: ";
    if (myList.searchValue(50)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}


// 2. Doubly Linked List
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* nextNode;
    node* previousNode;

    node(int value) {
        data = value;
        nextNode = NULL;
        previousNode = NULL;
    }
};

class DoublyLinkedList {
private:
    node* startNode;

public:
    DoublyLinkedList() {
        startNode = NULL;
    }

    void insertValue(int value) {
        node* newNode = new node(value);
        if (startNode == NULL) {
            startNode = newNode;
        } else {
            node* currentNode = startNode;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
            newNode->previousNode = currentNode;
        }
    }

    void deleteValue(int value) {
        if (startNode == NULL) {
            return;
        }

        node* currentNode = startNode;
        while (currentNode != NULL && currentNode->data != value) {
            currentNode = currentNode->nextNode;
        }

        if (currentNode == NULL) {
            return;
        }

        if (currentNode->previousNode != NULL) {
            currentNode->previousNode->nextNode = currentNode->nextNode;
        } else {
            startNode = currentNode->nextNode;
        }

        if (currentNode->nextNode != NULL) {
            currentNode->nextNode->previousNode = currentNode->previousNode;
        }

        delete currentNode;
    }

    bool searchValue(int value) {
        node* currentNode = startNode;
        while (currentNode != NULL) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->nextNode;
        }
        return false;
    }

    void displayListForward() {
        node* currentNode = startNode;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }

    void displayListBackward() {
        node* currentNode = startNode;
        if (currentNode == NULL) {
            return;
        }
        while (currentNode->nextNode != NULL) {
            currentNode = currentNode->nextNode;
        }
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->previousNode;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;
    myList.insertValue(100);
    myList.insertValue(200);
    myList.insertValue(300);

    cout << "List in Forward Order: ";
    myList.displayListForward();

    cout << "List in Backward Order: ";
    myList.displayListBackward();

    myList.deleteValue(200);
    cout << "After Deleting 200: ";
    myList.displayListForward();

    cout << "Searching for 300: ";
    if (myList.searchValue(300)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}


// (continued in next update...)

// (previous code for Singly and Doubly Linked List)

// 3. Two Linked Lists Connected
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* nextNode;

    node(int value) {
        data = value;
        nextNode = NULL;
    }
};

class ConnectedLists {
private:
    node* headOne;
    node* headTwo;

public:
    ConnectedLists() {
        headOne = NULL;
        headTwo = NULL;
    }

    void insertToFirst(int value) {
        node* newNode = new node(value);
        if (headOne == NULL) {
            headOne = newNode;
        } else {
            node* currentNode = headOne;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
        }
    }

    void insertToSecond(int value) {
        node* newNode = new node(value);
        if (headTwo == NULL) {
            headTwo = newNode;
        } else {
            node* currentNode = headTwo;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
        }
    }

    void connectLists() {
        if (headOne == NULL) {
            headOne = headTwo;
        } else {
            node* currentNode = headOne;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = headTwo;
        }
        headTwo = NULL;
    }

    void displayConnectedList() {
        node* currentNode = headOne;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    ConnectedLists myLists;
    myLists.insertToFirst(1);
    myLists.insertToFirst(2);
    myLists.insertToSecond(3);
    myLists.insertToSecond(4);

    myLists.connectLists();
    cout << "Connected List: ";
    myLists.displayConnectedList();

    return 0;
}


// 4. Stack
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* nextNode;

    node(int value) {
        data = value;
        nextNode = NULL;
    }
};

class Stack {
private:
    node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    void pushValue(int value) {
        node* newNode = new node(value);
        newNode->nextNode = topNode;
        topNode = newNode;
    }

    void popValue() {
        if (topNode == NULL) {
            return;
        }
        node* temp = topNode;
        topNode = topNode->nextNode;
        delete temp;
    }

    bool searchValue(int value) {
        node* currentNode = topNode;
        while (currentNode != NULL) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->nextNode;
        }
        return false;
    }

    void displayStack() {
        node* currentNode = topNode;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;
    myStack.pushValue(10);
    myStack.pushValue(20);
    myStack.pushValue(30);

    cout << "Stack: ";
    myStack.displayStack();

    myStack.popValue();
    cout << "After Pop: ";
    myStack.displayStack();

    return 0;
}


// 5. Queue
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* nextNode;

    node(int value) {
        data = value;
        nextNode = NULL;
    }
};

class Queue {
private:
    node* frontNode;
    node* rearNode;

public:
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    void enqueueValue(int value) {
        node* newNode = new node(value);
        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->nextNode = newNode;
            rearNode = newNode;
        }
    }

    void dequeueValue() {
        if (frontNode == NULL) {
            return;
        }
        node* temp = frontNode;
        frontNode = frontNode->nextNode;
        if (frontNode == NULL) {
            rearNode = NULL;
        }
        delete temp;
    }

    bool searchValue(int value) {
        node* currentNode = frontNode;
        while (currentNode != NULL) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->nextNode;
        }
        return false;
    }

    void displayQueue() {
        node* currentNode = frontNode;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueueValue(100);
    myQueue.enqueueValue(200);
    myQueue.enqueueValue(300);

    cout << "Queue: ";
    myQueue.displayQueue();

    myQueue.dequeueValue();
    cout << "After Dequeue: ";
    myQueue.displayQueue();

    return 0;
}


// (continued with Binary Tree, Binary Search Tree, and Heap in next update...)

// (Previous code for Linked List, Doubly Linked List, Two Connected Lists, Stack, and Queue)

// 6. Binary Tree
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* leftChild;
    node* rightChild;

    node(int value) {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BinaryTree {
private:
    node* rootNode;

    void insertHelper(node*& currentNode, int value) {
        if (currentNode == NULL) {
            currentNode = new node(value);
            return;
        }
        if (currentNode->leftChild == NULL) {
            insertHelper(currentNode->leftChild, value);
        } else {
            insertHelper(currentNode->rightChild, value);
        }
    }

    bool searchHelper(node* currentNode, int value) {
        if (currentNode == NULL) {
            return false;
        }
        if (currentNode->data == value) {
            return true;
        }
        return searchHelper(currentNode->leftChild, value) || searchHelper(currentNode->rightChild, value);
    }

    void inorderTraversal(node* currentNode) {
        if (currentNode != NULL) {
            inorderTraversal(currentNode->leftChild);
            cout << currentNode->data << " ";
            inorderTraversal(currentNode->rightChild);
        }
    }

public:
    BinaryTree() {
        rootNode = NULL;
    }

    void insertValue(int value) {
        insertHelper(rootNode, value);
    }

    bool searchValue(int value) {
        return searchHelper(rootNode, value);
    }

    void displayInorder() {
        inorderTraversal(rootNode);
        cout << endl;
    }
};

int main() {
    BinaryTree myTree;
    myTree.insertValue(10);
    myTree.insertValue(20);
    myTree.insertValue(30);

    cout << "Binary Tree Inorder Traversal: ";
    myTree.displayInorder();

    return 0;
}


// 7. Binary Search Tree
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* leftChild;
    node* rightChild;

    node(int value) {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BinarySearchTree {
private:
    node* rootNode;

    node* insertHelper(node* currentNode, int value) {
        if (currentNode == NULL) {
            return new node(value);
        }
        if (value < currentNode->data) {
            currentNode->leftChild = insertHelper(currentNode->leftChild, value);
        } else {
            currentNode->rightChild = insertHelper(currentNode->rightChild, value);
        }
        return currentNode;
    }

    node* deleteHelper(node* currentNode, int value) {
        if (currentNode == NULL) {
            return NULL;
        }
        if (value < currentNode->data) {
            currentNode->leftChild = deleteHelper(currentNode->leftChild, value);
        } else if (value > currentNode->data) {
            currentNode->rightChild = deleteHelper(currentNode->rightChild, value);
        } else {
            if (currentNode->leftChild == NULL) {
                node* temp = currentNode->rightChild;
                delete currentNode;
                return temp;
            } else if (currentNode->rightChild == NULL) {
                node* temp = currentNode->leftChild;
                delete currentNode;
                return temp;
            }
            node* successor = currentNode->rightChild;
            while (successor->leftChild != NULL) {
                successor = successor->leftChild;
            }
            currentNode->data = successor->data;
            currentNode->rightChild = deleteHelper(currentNode->rightChild, successor->data);
        }
        return currentNode;
    }

    bool searchHelper(node* currentNode, int value) {
        if (currentNode == NULL) {
            return false;
        }
        if (value == currentNode->data) {
            return true;
        }
        if (value < currentNode->data) {
            return searchHelper(currentNode->leftChild, value);
        }
        return searchHelper(currentNode->rightChild, value);
    }

    void inorderTraversal(node* currentNode) {
        if (currentNode != NULL) {
            inorderTraversal(currentNode->leftChild);
            cout << currentNode->data << " ";
            inorderTraversal(currentNode->rightChild);
        }
    }

public:
    BinarySearchTree() {
        rootNode = NULL;
    }

    void insertValue(int value) {
        rootNode = insertHelper(rootNode, value);
    }

    void deleteValue(int value) {
        rootNode = deleteHelper(rootNode, value);
    }

    bool searchValue(int value) {
        return searchHelper(rootNode, value);
    }

    void displayInorder() {
        inorderTraversal(rootNode);
        cout << endl;
    }
};

int main() {
    BinarySearchTree myBST;
    myBST.insertValue(50);
    myBST.insertValue(30);
    myBST.insertValue(70);
    myBST.insertValue(20);
    myBST.insertValue(40);
    myBST.insertValue(60);
    myBST.insertValue(80);

    cout << "BST Inorder: ";
    myBST.displayInorder();

    myBST.deleteValue(70);
    cout << "After Deleting 70: ";
    myBST.displayInorder();

    return 0;
}


// 8. Heap (Min Heap using array)
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heapData;

    void heapifyUp(int index) {
        while (index > 0 && heapData[index] < heapData[(index - 1) / 2]) {
            swap(heapData[index], heapData[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heapData.size() && heapData[left] < heapData[smallest]) {
            smallest = left;
        }
        if (right < heapData.size() && heapData[right] < heapData[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heapData[index], heapData[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insertValue(int value) {
        heapData.push_back(value);
        heapifyUp(heapData.size() - 1);
    }

    void deleteTop() {
        if (heapData.empty()) return;
        heapData[0] = heapData.back();
        heapData.pop_back();
        heapifyDown(0);
    }

    bool searchValue(int value) {
        for (int i = 0; i < heapData.size(); i++) {
            if (heapData[i] == value) return true;
        }
        return false;
    }

    void displayHeap() {
        for (int i = 0; i < heapData.size(); i++) {
            cout << heapData[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap myHeap;
    myHeap.insertValue(40);
    myHeap.insertValue(10);
    myHeap.insertValue(30);

    cout << "Heap: ";
    myHeap.displayHeap();

    myHeap.deleteTop();
    cout << "After Delete: ";
    myHeap.displayHeap();

    return 0;
}
